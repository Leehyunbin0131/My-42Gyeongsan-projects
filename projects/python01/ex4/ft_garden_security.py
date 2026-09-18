class Plant:
    def __init__(
        self,
        name: str,
        height: float,
        grow_level: float,
        age: int
    ) -> None:
        self._name = name
        self._init_height = 0.0
        self._height = 0.0
        self._grow_level = 0.0
        self._age = 0
        self.set_height(height)
        self.set_age(age)
        self._init_height = self._height
        self._grow_level = grow_level

    def age(self) -> None:
        self._age += 1

    def grow(self) -> None:
        self._height += self._grow_level

    def next_day(self) -> None:
        self.age()
        self.grow()

    def show(self) -> None:
        print(
            f"{self._name}: {self.get_height():.1f}cm, "
            f"{self.get_age()} days old"
        )

    def simulate(self, days: int) -> None:
        self.show()
        for i in range(1, days + 1):
            self.next_day()
            print(f"=== Day {i} ===")
            self.show()
        print(
            f"Growth this week: {self._height - self._init_height:.1f}cm"
        )

    def set_height(self, height: float) -> bool:
        if height < 0:
            print(f"{self._name}: Error, height can't be negative")
            return False
        self._height = height
        return True

    def set_age(self, age: int) -> bool:
        if age < 0:
            print(f"{self._name}: Error, age can't be negative")
            return False
        self._age = age
        return True

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age


if __name__ == "__main__":
    print("=== Garden Security System ===")
    plant = Plant("Rose", 15.0, 0.8, 10)
    print("Plant created:", end=" ")
    plant.show()
    print("")
    if plant.set_height(25):
        print(f"Height updated: {plant.get_height()}cm")
    else:
        print("Height update rejected")
    if plant.set_age(30):
        print(f"Age updated: {plant.get_age()} days")
    else:
        print("Age update rejected")
    print("")
    if plant.set_height(-50):
        print(f"Height updated: {plant.get_height()}cm")
    else:
        print("Height update rejected")
    if plant.set_age(-1):
        print(f"Age updated: {plant.get_age()} days")
    else:
        print("Age update rejected")
    print("")
    print("Current state:", end=" ")
    plant.show()
