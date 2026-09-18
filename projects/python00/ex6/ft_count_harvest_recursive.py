def ft_count_harvest_recursive() -> None:
    days: int = int(input("Days until harvest: "))

    def count(day: int) -> None:
        if day > days:
            return
        print("Day", day)
        count(day + 1)

    count(1)
    print("Harvest time!")
