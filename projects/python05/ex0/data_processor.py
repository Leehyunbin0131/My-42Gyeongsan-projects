from abc import ABC, abstractmethod
from typing import Any


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

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")

        if not isinstance(data, list):
            data = [data]

        for entry in data:
            text: str = str(entry)
            if "log_level" in entry and "log_message" in entry:
                text = f"{entry['log_level']}: {entry['log_message']}"
            self._data.append(text)


if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===\n")

    print("Testing Numeric Processor...")
    numeric_processor = NumericProcessor()

    print(
        " Trying to validate input '42': "
        f"{numeric_processor.validate(42)}"
    )
    print(
        " Trying to validate input 'Hello': "
        f"{numeric_processor.validate('Hello')}"
    )

    print(" Test invalid ingestion of string 'foo' without prior validation:")
    try:
        numeric_processor.ingest("foo")
    except ValueError as error:
        print(f" Got exception: {error}")

    print(" Processing data: [1, 2, 3, 4, 5]")
    numeric_processor.ingest([1, 2, 3, 4, 5])

    print(" Extracting 3 values...")
    for _ in range(3):
        rank, value = numeric_processor.output()
        print(f" Numeric value {rank}: {value}")

    print()
    print("Testing Text Processor...")
    text_processor = TextProcessor()

    print(
        " Trying to validate input '42': "
        f"{text_processor.validate(42)}"
    )

    print(" Processing data: ['Hello', 'Nexus', 'World']")
    text_processor.ingest(["Hello", "Nexus", "World"])

    print(" Extracting 1 value...")
    rank, value = text_processor.output()
    print(f" Text value {rank}: {value}")

    print()
    print("Testing Log Processor...")
    log_processor = LogProcessor()

    print(
        " Trying to validate input 'Hello': "
        f"{log_processor.validate('Hello')}"
    )

    logs: list[dict[str, str]] = [
        {
            "log_level": "NOTICE",
            "log_message": "Connection to server"
        },
        {
            "log_level": "ERROR",
            "log_message": "Unauthorized access!!"
        }
    ]

    print(f" Processing data: {logs}")
    log_processor.ingest(logs)

    print(" Extracting 2 values...")
    for _ in range(2):
        rank, value = log_processor.output()
        print(f" Log entry {rank}: {value}")
