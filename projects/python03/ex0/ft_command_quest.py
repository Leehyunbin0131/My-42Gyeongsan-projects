import sys

if __name__ == "__main__":
    script_name: str
    args: list[str]
    script_name, *args = sys.argv

    print("=== Command Quest ===")

    print(f"Program name: {script_name}")

    if len(args) == 0:
        print("No arguments provided!")
    else:
        index: int = 1
        arg: str
        print(f"Arguments received: {len(args)}")
        for arg in args:
            print(f"Argument {index}: {arg}")
            index += 1

    print("Total arguments:", len(sys.argv))
