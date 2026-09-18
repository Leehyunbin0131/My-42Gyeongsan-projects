class Plant:
    def __init__(
        self,
        name: str,
        height: float,
        grow_level: float,
        age: int
    ) -> None:
        self._name = name
        self._init_height = height
        self._height = height
        self._grow_level = grow_level
        self._age = age

    def age(self) -> None:
        self._age += 1

    def grow(self) -> None:
        self._height += self._grow_level

    def next_day(self) -> None:
        self.age()
        self.grow()

    def show(self) -> None:
        print(
            f"{self._name}: {self._height:.1f}cm, "
            f"{self._age} days old"
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


if __name__ == "__main__":
    print("=== Garden Plant Growth ===")
    plant1 = Plant("Rose", 25.0, 0.8, 30)
    plant1.simulate(7)
