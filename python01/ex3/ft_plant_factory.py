#!usr/bin/env python3

class Plant:
    def __init__(self, name: str, height: int, days: int):
        self.name = name
        self.height = height
        self.days = days

    def grow(self):
        self.height += 1

    def age(self):
        self.days += 1

    def get_info(self):
        print(f"{self.name}: {self.height}, {self.days} days old")


def main():

    plants_data = [
        ("Rose", 25, 30),
        ("Oak", 200, 365),
        ("Cactus", 5, 90),
        ("Sunflower", 80, 45),
        ("Fern", 15, 120)
    ]
    plants = []
    i = 0
    while (i < 5):
        plants.append(Plant(
            plants_data[i][0],
            plants_data[i][1],
            plants_data[i][2])
        )
        print(f"Created: {plants[i].get_info()}")
        i += 1


if __name__ == "__main__":
    main()
