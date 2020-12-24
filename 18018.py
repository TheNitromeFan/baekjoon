import sys


def eliminates(animals, animal):
    for animal1 in animals:
        if animal1 == animal:
            continue
        if animal1[0] == animal[-1]:
            return False
    return True


def play(previous, animals):
    for animal in animals:
        if animal[0] == previous[-1] and eliminates(animals, animal):
            return animal + "!"
    for animal in animals:
        if animal[0] == previous[-1]:
            return animal
    return "?"


def main():
    previous = sys.stdin.readline().rstrip()
    n = int(sys.stdin.readline())
    animals = []
    for _ in range(n):
        animals.append(sys.stdin.readline().rstrip())
    print(play(previous, animals))


main()
