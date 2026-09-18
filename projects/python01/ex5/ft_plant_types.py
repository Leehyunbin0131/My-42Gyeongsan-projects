class Plant:
    def __init__(
        self,
        name: str,
        height: float,
        grow_level: float,
        age: int
    ) -> None:
        self._name = name
        self._height = 0.0
        self._grow_level = 0.0
        self._age = 0
        self.set_height(height)
        self.set_age(age)
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
            f"{self.get_name()}: {self.get_height():.1f}cm, "
            f"{self.get_age()} days old"
        )

    def simulate(self, days: int) -> None:
        for _ in range(days):
            self.next_day()

    def set_height(self, height: float) -> bool:
        if height < 0:
            print(f"{self.get_name()}: Error, height can't be negative")
            return False
        self._height = height
        return True

    def set_age(self, age: int) -> bool:
        if age < 0:
            print(f"{self.get_name()}: Error, age can't be negative")
            return False
        self._age = age
        return True

    def get_height(self) -> float:
        return self._height

    def get_age(self) -> int:
        return self._age

    def get_name(self) -> str:
        return self._name


class Flower(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        grow_level: float,
        age: int,
        color: str
    ) -> None:
        super().__init__(name, height, grow_level, age)
        self.color = color
        self.is_bloom = False

    def bloom(self) -> None:
        self.is_bloom = True

    def show(self) -> None:
        super().show()
        print(f" Color: {self.color}")
        if self.is_bloom:
            print(f" {self.get_name()} is blooming beautifully!")
        else:
            print(f" {self.get_name()} has not bloomed yet")


class Tree(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        grow_level: float,
        age: int,
        trunk_diameter: float
    ) -> None:
        super().__init__(name, height, grow_level, age)
        self.trunk_diameter = trunk_diameter

    def produce_shade(self) -> None:
        print(
            f"Tree {self.get_name()} now produces a shade of "
            f"{self.get_height():.1f}cm "
            f"long and {self.trunk_diameter:.1f}cm wide."
        )

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter:.1f}cm")


class Vegetable(Plant):
    def __init__(
        self,
        name: str,
        height: float,
        grow_level: float,
        age: int,
        harvest_season: str,
    ) -> None:
        super().__init__(name, height, grow_level, age)
        self.harvest_season = harvest_season
        self.nutritional_value = 0

    def next_day(self) -> None:
        super().next_day()
        self.nutritional_value += 1

    def show(self) -> None:
        super().show()
        print(f" Harvest season: {self.harvest_season}")
        print(f" Nutritional value: {self.nutritional_value}")


if __name__ == "__main__":
    print("=== Garden Plant Types ===")
    print("=== Flower")
    plant1 = Flower("Rose", 15.0, 1, 10, "red")
    plant1.show()
    print(f"[asking the {plant1.get_name()} to bloom]")
    plant1.bloom()
    plant1.show()

    print("")
    print("=== Tree")
    plant2 = Tree("Oak", 200.0, 1, 365, 5.0)
    plant2.show()
    print(f"[asking the {plant2.get_name()} to produce shade]")
    plant2.produce_shade()

    print("")
    print("=== Vegetable")
    plant3 = Vegetable("Tomato", 5.0, 2.1, 10, "April")
    plant3.show()
    print("[make tomato grow and age for 20 days]")
    plant3.simulate(20)
    plant3.show()
