class Plant:
    class Statistics:
        def __init__(self) -> None:
            self._count_grow = 0
            self._count_age = 0
            self._count_show = 0

        def increase_grow(self) -> None:
            self._count_grow += 1

        def increase_age(self) -> None:
            self._count_age += 1

        def increase_show(self) -> None:
            self._count_show += 1

        def show_stats(self) -> None:
            print(
                f"Stats: {self._count_grow} grow, "
                f"{self._count_age} age, "
                f"{self._count_show} show"
            )

    def __init__(
        self,
        name: str = "",
        height: float = 0.0,
        grow_level: float = 0.0,
        age: int = 0
    ) -> None:
        self._name = name
        self._height = 0.0
        self._age = 0
        self.set_height(height)
        self.set_age(age)
        self._grow_level = grow_level
        self._stats = self.Statistics()

    def show_stats(self) -> None:
        self._stats.show_stats()

    @classmethod
    def make_unknown_plant(cls) -> "Plant":
        return cls("Unknown plant", 0.0, 0.0, 0)

    @staticmethod
    def is_year_over(age: int) -> bool:
        return age > 365

    def age(self, days: int = 1) -> None:
        self._age += days
        self._stats.increase_age()

    def grow(self) -> None:
        self._height += self._grow_level
        self._stats.increase_grow()

    def next_day(self) -> None:
        self.age()
        self.grow()

    def show(self) -> None:
        self._stats.increase_show()
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


class Seed(Flower):
    def __init__(
        self,
        name: str,
        height: float,
        grow_level: float,
        age: int,
        color: str,
        get_seeds: int
    ) -> None:
        super().__init__(name, height, grow_level, age, color)
        self.quantity = get_seeds

    def show(self) -> None:
        super().show()
        if self.is_bloom:
            print(f" Seeds: {self.quantity}")
        else:
            print(" Seeds: 0")


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
        self._count_shade = 0

    def increase_shade(self) -> None:
        self._count_shade += 1

    def produce_shade(self) -> None:
        self.increase_shade()
        print(
            f"Tree {self.get_name()} now produces a shade of "
            f"{self.get_height():.1f}cm "
            f"long and {self.trunk_diameter:.1f}cm wide."
        )

    def show(self) -> None:
        super().show()
        print(f" Trunk diameter: {self.trunk_diameter:.1f}cm")

    def show_stats(self) -> None:
        super().show_stats()
        print(f" {self._count_shade} shade")


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


def display_statistics(plant: Plant) -> None:
    print(f"[statistics for {plant.get_name()}]")
    plant.show_stats()


if __name__ == "__main__":
    print("=== Garden statistics ===")
    print("=== Check year-old")
    print(f"Is 30 days more than a year? -> {Plant.is_year_over(30)}")
    print(f"Is 400 days more than a year? -> {Plant.is_year_over(400)}")

    print("")
    print("=== Flower")
    plant1 = Flower("Rose", 15, 8.0, 10, "red")
    plant1.show()
    display_statistics(plant1)
    print("[asking the rose to grow and bloom]")
    plant1.grow()
    plant1.bloom()
    plant1.show()
    display_statistics(plant1)

    print("")
    print("=== Tree")
    plant2 = Tree("oak", 200.0, 0, 365, 5.0)
    plant2.show()
    display_statistics(plant2)
    print("[asking the oak to produce shade]")
    plant2.produce_shade()
    display_statistics(plant2)

    print("")
    print("=== Seed")
    seed = Seed("Sunflower", 80.0, 30.0, 45, "yellow", 42)
    seed.show()
    print(f"[make {seed.get_name()} grow, age and bloom]")
    seed.grow()
    seed.age(20)
    seed.bloom()
    seed.show()
    display_statistics(seed)

    print("")
    print("=== Anonymous")
    plant_unknown = Plant.make_unknown_plant()
    plant_unknown.show()
    display_statistics(plant_unknown)
