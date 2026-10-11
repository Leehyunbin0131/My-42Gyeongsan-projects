from ex1 import HealingCreatureFactory, TransformCreatureFactory


def heal_factory(factory: HealingCreatureFactory) -> None:
    print(" base:")
    test_factory = factory
    monster1 = test_factory.create_base()
    monster2 = test_factory.create_evolved()
    print(monster1.describe())
    print(monster1.attack())
    print(monster1.heal())
    print(" evolved:")
    print(monster2.describe())
    print(monster2.attack())
    print(monster2.heal())


def trans_factory(factory: TransformCreatureFactory) -> None:
    print(" base:")
    test_factory = factory
    monster1 = test_factory.create_base()
    monster2 = test_factory.create_evolved()
    print(monster1.describe())
    print(monster1.attack())
    print(monster1.transform())
    print(monster1.attack())
    print(monster1.revert())
    print(" evolved:")
    print(monster2.describe())
    print(monster2.attack())
    print(monster2.transform())
    print(monster2.attack())
    print(monster2.revert())


def main() -> None:
    print("Testing Creature with healing capability")
    heal_factory(HealingCreatureFactory())
    print("")
    print("Testing Creature with transform capability")
    trans_factory(TransformCreatureFactory())


if __name__ == "__main__":
    main()
