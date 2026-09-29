import sys


if __name__ == "__main__":
    print("=== Inventory System Analysis ===")
    inventory: dict[str, int] = {}

    arg: str
    for arg in sys.argv[1:]:
        parts = arg.split(":")
        if len(parts) != 2:
            print(f"Error - invalid parameter '{arg}'")
            continue

        item_name: str = parts[0]
        quantity_str: str = parts[1]

        if item_name in inventory.keys():
            print(f"Redundant item '{item_name}' - discarding")
            continue

        try:
            inventory.update({item_name: int(quantity_str)})
        except ValueError as e:
            print(f"Quantity error for '{item_name}': {e}")

    print(f"Got inventory: {inventory}")
    print(f"Item list: {list(inventory.keys())}")

    total_quantity: int = sum(inventory.values())
    print(
        f"Total quantity of the {len(inventory)} "
        f"items: {total_quantity}"
    )

    if inventory:
        first_item: str = list(inventory.keys())[0]
        first_quantity: int = list(inventory.values())[0]

        item_max: str = first_item
        quantity_max: int = first_quantity
        item_min: str = first_item
        quantity_min: int = first_quantity

        for item in inventory.keys():
            quantity: int = inventory[item]
            percentage: float = (quantity / total_quantity) * 100
            print(f"Item {item} represents {percentage:.1f}%")

            if quantity > quantity_max:
                quantity_max = quantity
                item_max = item
            if quantity < quantity_min:
                quantity_min = quantity
                item_min = item

        print(f"Item most abundant: {item_max} with quantity {quantity_max}")
        print(f"Item least abundant: {item_min} with quantity {quantity_min}")

    inventory.update({"magic_item": 1})
    print(f"Updated inventory: {inventory}")
