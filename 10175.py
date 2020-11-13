animals = {"W": "Wolf", "M": "Mountain Lion", "C": "Coyote", "B": "Bobcat"}
values = {"W": 3, "M": 4, "C": 1, "B": 2}


def dominant_species():
    location, sightings = input().split()
    dom = sorted(((animal, sightings.count(animal) * values[animal]) for animal in values), key=lambda x: x[1])
    if dom[-1][1] == dom[-2][1]:
        return location, None
    else:
        return location, animals[dom[-1][0]]


def main():
    n = int(input())
    for _ in range(n):
        location, answer = dominant_species()
        if answer is None:
            print("{}: There is no dominant species".format(location))
        else:
            print("{}: The {} is the dominant species".format(location, answer))


main()
