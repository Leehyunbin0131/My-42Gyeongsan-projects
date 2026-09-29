import sys

if __name__ == "__main__":
    scores: list[int] = []
    arg: str
    score: int

    print("=== Player Score Analytics ===")

    for arg in sys.argv[1:]:
        try:
            score = int(arg)
        except ValueError:
            print(f"Invalid parameter: '{arg}'")
        else:
            scores += [score]

    if not scores:
        print(
            "No scores provided. Usage: "
            "python3 ft_score_analytics.py <score1> <score2> ..."
        )
    else:
        total: int = sum(scores)
        highest: int = max(scores)
        lowest: int = min(scores)

        print(f"Scores processed: {scores}")
        print(f"Total players: {len(scores)}")
        print(f"Total score: {total}")
        print(f"Average score: {total / len(scores)}")
        print(f"High score: {highest}")
        print(f"Low score: {lowest}")
        print(f"Score range: {highest - lowest}")
