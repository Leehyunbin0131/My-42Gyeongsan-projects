class GardenError(Exception):
    def __init__(self, message="A garden error occurred"):
        super().__init__(message)


class PlantError(GardenError):
    def __init__(self, message="Unknown plant error"):
        super().__init__(message)


class WaterError(GardenError):
    def __init__(self, message="Unknown water error"):
        super().__init__(message)


def plant_issue(day: int):
    if day > 15:
        raise PlantError("The tomato plant is wilting!")
    else:
        print("The tomato plant is fine")


def water_issue(day: int):
    if day > 2:
        raise WaterError("Not enough water in the tank!")
    else:
        print("There is enough water.")


if __name__ == "__main__":
    print("Custom Garden Errors Demo ===")
    print("Testing PlantError...")
    try:
        plant_issue(16)
    except PlantError as e:
        print(f"Caught PlantError: {e}")

    print("Testing WaterError...")
    try:
        water_issue(5)
    except WaterError as e:
        print(f"Caught WaterError: {e}")

    print("Testing catching all garden errors...")
    try:
        plant_issue(30)
    except GardenError as e:
        print(f"Caught GardenError: {e}")
    try:
        water_issue(5)
    except GardenError as e:
        print(f"Caught GardenError: {e}")

    print("All custom error types work correctly!")
