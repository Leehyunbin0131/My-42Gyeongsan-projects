from ex0 import CreatureFactory, FlameFactory, AquaFactory


def test_factory(factory: CreatureFactory) -> None:
    test_factory = factory
    monster1 = test_factory.create_base()
    monster2 = test_factory.create_evolved()
    print(monster1.describe())
    print(monster1.attack())
    print(monster2.describe())
    print(monster2.attack())


def test_battle(factory1: CreatureFactory, factory2: CreatureFactory) -> None:
    test_factory1 = factory1
    test_factory2 = factory2
    monster1 = test_factory1.create_base()
    monster2 = test_factory2.create_base()
    print(monster1.describe())
    print(" vs.")
    print(monster2.describe())
    print(" fight!")
    print(monster1.attack())
    print(monster2.attack())


def main() -> None:
    print("Testing factory")
    test_factory(FlameFactory())
    print("")

    print("Testing factory")
    test_factory(AquaFactory())
    print("")

    print("Testing Battle")
    test_battle(FlameFactory(), AquaFactory())


if __name__ == "__main__":
    main()
