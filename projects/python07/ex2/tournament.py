from ex0.factory import CreatureFactory
from .error import BattleError
from .strategy import BattleStrategy


def run_tournament(
    opponents: list[tuple[CreatureFactory, BattleStrategy]],
) -> None:
    """Run each factory's base creature against every other opponent once.

    Opponents pair a factory with its strategy. BattleError aborts the event.
    """
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")
    try:
        creatures = [
            (factory.create_base(), strategy)
            for factory, strategy in opponents
        ]
        for i, (creature1, strategy1) in enumerate(creatures):
            for j in range(i + 1, len(creatures)):
                creature2, strategy2 = creatures[j]
                print()
                print("* Battle *")
                print(creature1.describe())
                print(" vs.")
                print(creature2.describe())
                print(" now fight!")
                print(strategy1.act(creature1))
                print(strategy2.act(creature2))
    except BattleError as error:
        print(f"Battle error, aborting tournament: {error}")
