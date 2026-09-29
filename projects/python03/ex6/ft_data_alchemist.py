import random


if __name__ == "__main__":
    print("=== Game Data Alchemist ===")

    players: list[str] = [
        "Alice", "bob", "Charlie", "dylan", "Emma",
        "Gregory", "john", "kevin", "Liam"
    ]

    capitalized: list[str] = [name.capitalize() for name in players]
    originally_capitalized: list[str] = [
        name for name in players if name[0].isupper()
    ]

    print(f"\nInitial list of players: {players}")
    print(f"New list with all names capitalized: {capitalized}")
    print(f"New list of capitalized names only: {originally_capitalized}")

    scores: dict[str, int] = {
        name: random.randint(0, 1000) for name in capitalized
    }
    average: float = sum([scores[name] for name in scores]) / len(scores)
    high_scores: dict[str, int] = {
        name: scores[name] for name in scores if scores[name] > average
    }

    print(f"\nScore dict: {scores}")
    print(f"Score average is {average:.2f}")
    print(f"High scores: {high_scores}")
