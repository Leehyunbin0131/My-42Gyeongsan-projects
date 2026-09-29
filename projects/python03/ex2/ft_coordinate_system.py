import math


def get_player_pos() -> tuple[float, float, float]:
    user_input: str
    x_str: str
    y_str: str
    z_str: str
    value: str
    x_float: float
    y_float: float
    z_float: float

    while True:
        values: list[float] = []
        has_error: bool = False

        user_input = input(
            "Enter new coordinates as floats in format 'x,y,z': "
        )

        try:
            x_str, y_str, z_str = user_input.split(",")
        except ValueError:
            print("Invalid syntax")
            continue

        for value in (x_str, y_str, z_str):
            try:
                values += [float(value)]
            except ValueError as e:
                print(f"Error on parameter '{value}': {e}")
                has_error = True

        if has_error:
            continue

        x_float, y_float, z_float = values
        return x_float, y_float, z_float


if __name__ == "__main__":
    print("=== Game Coordinate System ===")
    print()
    print("Get a first set of coordinates")

    first_pos: tuple[float, float, float] = get_player_pos()

    x1: float
    y1: float
    z1: float
    x1, y1, z1 = first_pos

    print(f"Got a first tuple: {first_pos}")
    print(f"It includes: X={x1}, Y={y1}, Z={z1}")

    distance_to_center: float = math.sqrt(x1**2 + y1**2 + z1**2)
    print(f"Distance to center: {round(distance_to_center, 4)}")

    print()
    print("Get a second set of coordinates")

    second_pos: tuple[float, float, float] = get_player_pos()

    x2: float
    y2: float
    z2: float
    x2, y2, z2 = second_pos

    distance: float = math.sqrt(
        (x2 - x1)**2 + (y2 - y1)**2 + (z2 - z1)**2
    )
    print(f"Distance between the 2 sets of coordinates: {round(distance, 4)}")
