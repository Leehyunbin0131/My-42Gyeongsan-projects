from abc import ABC, abstractmethod
from typing import Any, Protocol


class DataProcessor(ABC):
    def __init__(self) -> None:
        self._data: list[str] = []
        self._rank: int = 0

    @abstractmethod
    def validate(self, data: Any) -> bool:
        pass

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

    def output(self) -> tuple[int, str]:
        if not self._data:
            raise ValueError("No data to output")

        value: str = self._data.pop(0)
        rank: int = self._rank
        self._rank += 1
        return rank, value

    def get_stats(self) -> tuple[int, int]:
        remaining: int = len(self._data)
        total: int = self._rank + remaining
        return total, remaining


class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, (int, float)):
            return True

        if isinstance(data, list):
            for item in data:
                if not isinstance(item, (int, float)):
                    return False
            return True

        return False

    def ingest(self, data: int | float | list[int | float]) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data")

        if isinstance(data, list):
            for item in data:
                self._data.append(str(item))
        else:
            self._data.append(str(data))


class TextProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, str):
            return True

        if isinstance(data, list):
            for item in data:
                if not isinstance(item, str):
                    return False
            return True

        return False

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")

        if isinstance(data, list):
            for item in data:
                self._data.append(item)
        else:
            self._data.append(data)


class LogProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, dict):
            for key, value in data.items():
                if not isinstance(key, str) or not isinstance(value, str):
                    return False
            return True

        if isinstance(data, list):
            for item in data:
                if not isinstance(item, dict):
                    return False
                if not self.validate(item):
                    return False
            return True

        return False

    def ingest(
        self,
        data: dict[str, str] | list[dict[str, str]]
    ) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")

        if not isinstance(data, list):
            data = [data]

        for entry in data:
            text: str = str(entry)

            if "log_level" in entry and "log_message" in entry:
                text = f"{entry['log_level']}: {entry['log_message']}"

            self._data.append(text)


class ExportPlugin(Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        ...


class CSVExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        fields: list[str] = []

        for _, value in data:
            if any(char in value for char in (",", '"', "\n", "\r")):
                value = '"' + value.replace('"', '""') + '"'
            fields.append(value)

        print("CSV Output:")
        print(",".join(fields))


class JSONExportPlugin:
    def _quote(self, value: str) -> str:
        escaped: list[str] = []

        for char in value:
            if char == '"':
                escaped.append('\\"')
            elif char == "\\":
                escaped.append("\\\\")
            elif ord(char) < 32:
                escaped.append(f"\\u{ord(char):04x}")
            else:
                escaped.append(char)

        return '"' + "".join(escaped) + '"'

    def process_output(self, data: list[tuple[int, str]]) -> None:
        items: list[str] = []

        for rank, value in data:
            items.append(f'"item_{rank}": {self._quote(value)}')

        print("JSON Output:")
        print("{" + ", ".join(items) + "}")


class DataStream:
    def __init__(self) -> None:
        self._processors: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self._processors.append(proc)

    def process_stream(self, stream: list[Any]) -> None:
        for data in stream:
            handled: bool = False

            for processor in self._processors:
                if processor.validate(data):
                    processor.ingest(data)
                    handled = True
                    break

            if not handled:
                print(
                    "DataStream error - Can't process element in stream: "
                    f"{data}"
                )

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")

        if not self._processors:
            print("No processor found, no data")
            return

        for processor in self._processors:
            name: str = type(processor).__name__.replace(
                "Processor", " Processor"
            )
            total, remaining = processor.get_stats()

            print(
                f"{name}: total {total} items processed, "
                f"remaining {remaining} on processor"
            )

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        if nb < 0:
            raise ValueError("Output count cannot be negative")

        for processor in self._processors:
            _, remaining = processor.get_stats()
            data: list[tuple[int, str]] = []

            for _ in range(min(nb, remaining)):
                data.append(processor.output())

            if data:
                plugin.process_output(data)


def main() -> None:
    print("=== Code Nexus - Data Pipeline ===")
    print()

    print("Initialize Data Stream...")
    stream = DataStream()
    print()

    stream.print_processors_stats()
    print()

    print("Registering Processors")
    stream.register_processor(NumericProcessor())
    stream.register_processor(TextProcessor())
    stream.register_processor(LogProcessor())
    print()

    batch: list[Any] = [
        "Hello world",
        [3.14, -1, 2.71],
        [
            {
                "log_level": "WARNING",
                "log_message": "Telnet access! Use ssh instead"
            },
            {
                "log_level": "INFO",
                "log_message": "User wil is connected"
            }
        ],
        42,
        ["Hi", "five"]
    ]

    print(f"Send first batch of data on stream: {batch}")
    stream.process_stream(batch)
    print()

    stream.print_processors_stats()
    print()

    csv_plugin = CSVExportPlugin()

    print("Send 3 processed data from each processor to a CSV plugin:")
    stream.output_pipeline(3, csv_plugin)
    print()

    stream.print_processors_stats()
    print()

    next_batch: list[Any] = [
        21,
        ["I love AI", "LLMs are wonderful", "Stay healthy"],
        [
            {
                "log_level": "ERROR",
                "log_message": "500 server crash"
            },
            {
                "log_level": "NOTICE",
                "log_message": "Certificate expires in 10 days"
            }
        ],
        [32, 42, 64, 84, 128, 168],
        "World hello"
    ]

    print(f"Send another batch of data: {next_batch}")
    stream.process_stream(next_batch)
    print()

    stream.print_processors_stats()
    print()

    json_plugin = JSONExportPlugin()

    print("Send 5 processed data from each processor to a JSON plugin:")
    stream.output_pipeline(5, json_plugin)
    print()

    stream.print_processors_stats()


if __name__ == "__main__":
    main()
