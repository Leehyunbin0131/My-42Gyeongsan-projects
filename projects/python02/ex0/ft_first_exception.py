def input_temperature(temp_str: str) -> int:
    return int(temp_str)


def test_temperature() -> None:
    print("Garden Temperature ===")
    print("Input data is '25'")
    try:
        input_temperature("25")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")
    print("Temperature is now 25°C")

    print("Input data is 'abc'")
    try:
        input_temperature("abc")
    except ValueError as e:
        print(f"Caught input_temperature error: {e}")

    print("All tests completed program didn't crash!")


if __name__ == "__main__":
    test_temperature()
