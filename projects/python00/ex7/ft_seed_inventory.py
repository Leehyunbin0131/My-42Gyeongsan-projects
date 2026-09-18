def ft_seed_inventory(seed_type: str, quantity: int, unit: str) -> None:
    type: str = seed_type.capitalize()
    s: str = ""
    if unit == "packets":
        s = f"{quantity} packets available."
    elif unit == "grams":
        s = f"{quantity} grams total"
    elif unit == "area":
        s = f"covers {quantity} square meters"
    else:
        print("Unknown unit type")
        return
    print(type, "seeds:", s)
