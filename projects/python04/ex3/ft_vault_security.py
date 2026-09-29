def secure_archive(
    file_name: str,
    mode: str = "r",
    content: str = ""
) -> tuple[bool, str]:
    if mode not in ("r", "w"):
        return False, "Invalid mode: use 'r' or 'w'."

    try:
        if mode == "r":
            with open(file_name, "r", encoding="utf-8") as file:
                text: str = file.read()
            return True, text

        with open(file_name, "w", encoding="utf-8") as file:
            file.write(content)
        return True, "Content successfully written to file"

    except (OSError, UnicodeDecodeError, UnicodeEncodeError) as error:
        return False, str(error)


def main() -> None:
    print("=== Cyber Archives Security ===")
    print()

    print("Using 'secure_archive' to read from a nonexistent file:")
    print(secure_archive("/not/existing/file"))
    print()

    print("Using 'secure_archive' to read from an inaccessible file:")
    print(secure_archive("/etc/shadow"))
    print()

    print("Using 'secure_archive' to read from a regular file:")
    success, content = secure_archive("ancient_fragment.txt")
    print((success, content))
    print()

    if success:
        print(
            "Using 'secure_archive' to write previous content to a new "
            "file:"
        )
        print(secure_archive("new_fragment.txt", "w", content))


if __name__ == "__main__":
    main()
