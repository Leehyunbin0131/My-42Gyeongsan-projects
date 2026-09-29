import random


ACHIEVEMENTS: list[str] = [
    "First Steps",
    "Boss Slayer",
    "Master Explorer",
    "Treasure Hunter",
    "Speed Runner",
    "Survivor",
    "Crafting Genius",
    "World Savior",
    "Collector Supreme",
    "Untouchable",
    "Strategist",
    "Unstoppable",
    "Sharp Mind",
    "Hidden Path Finder",
]


def gen_player_achievements() -> set[str]:
    count: int = random.randint(6, 10)
    return set(random.sample(ACHIEVEMENTS, count))


if __name__ == "__main__":
    players: list[tuple[str, set[str]]] = [
        ("Alice", gen_player_achievements()),
        ("Bob", gen_player_achievements()),
        ("Charlie", gen_player_achievements()),
        ("Dylan", gen_player_achievements()),
    ]

    name: str
    achievements: set[str]
    other_name: str
    other_achievements: set[str]

    print("=== Achievement Tracker System ===")
    print()

    for name, achievements in players:
        print(f"Player {name}: {achievements}")

    all_distinct: set[str] = set()
    common: set[str] = players[0][1]

    for name, achievements in players:
        all_distinct = all_distinct.union(achievements)
        common = common.intersection(achievements)

    print()
    print(f"All distinct achievements: {all_distinct}")
    print()
    print(f"Common achievements: {common}")
    print()

    others: set[str]
    exclusive: set[str]

    for name, achievements in players:
        others = set()

        for other_name, other_achievements in players:
            if other_name != name:
                others = others.union(other_achievements)

        exclusive = achievements.difference(others)
        print(f"Only {name} has: {exclusive}")

    all_achievements: set[str] = set(ACHIEVEMENTS)
    missing: set[str]

    print()

    for name, achievements in players:
        missing = all_achievements.difference(achievements)
        print(f"{name} is missing: {missing}")
