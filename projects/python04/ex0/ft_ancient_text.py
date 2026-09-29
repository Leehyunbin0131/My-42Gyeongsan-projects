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
            print(f"Error opening file '{file_name}': {error}")
            continue

        print("---")
        print()
        print(text)
        print()
        print("---")
        print(f"File '{file_name}' closed.")


if __name__ == "__main__":
    main()
