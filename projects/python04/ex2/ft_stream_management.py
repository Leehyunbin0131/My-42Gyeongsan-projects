import sys
import typing


def main() -> None:
    file_name: str = ""
    if len(sys.argv) < 2:
        print("Usage: ft_ancient_text.py <file>")
        return
    print("=== Cyber Archives Recovery ===")
    for file_name in sys.argv[1:]:
        print(f"Accessing file '{file_name}'")

        try:
            # open(file, mode='r', buffering=-1, encoding=None, errors=None,
            # newline=None, closefd=True, opener=None)
            file: typing.IO[str] = open(file_name, "r", encoding="utf-8")
            # open return type = io.TextIOWrapper
            try:
                text: str = file.read()
            finally:
                file.close()
        except (OSError, UnicodeDecodeError) as error:
            print(
                f"[STDERR] Error opening file '{file_name}': {error}",
                file=sys.stderr
            )
            continue

        print("---")
        print()
        print(text)
        print()
        print("---")
        print(f"File '{file_name}' closed.")
        print()

        transformed: str = text.replace("\n", "#\n")
        if text and not text.endswith("\n"):
            transformed += "#"

        print("Transform data:")
        print("---")
        print()
        print(transformed)
        print()
        print("---")

        sys.stdout.write("Enter new file name (or empty): ")
        sys.stdout.flush()
        new_file_name: str = sys.stdin.readline().rstrip("\n")
        if not new_file_name:
            print("Not saving data.")
            continue

        print(f"Saving data to '{new_file_name}'")
        try:
            new_file: typing.IO[str] = open(
                new_file_name, "w", encoding="utf-8"
            )
            try:
                new_file.write(transformed)
            finally:
                new_file.close()
        except (OSError, UnicodeEncodeError) as error:
            print(
                f"[STDERR] Error opening file '{file_name}': {error}",
                file=sys.stderr
            )
            continue

        print(f"Data saved in file '{new_file_name}'.")


if __name__ == "__main__":
    main()
