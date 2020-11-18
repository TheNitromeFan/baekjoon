import sys


def sorting_key(word, alphabet):
    return [alphabet.index(letter) for letter in word]


def main():
    year = 0
    while True:
        line = sys.stdin.readline().rstrip()
        if line == "0":
            break
        year += 1
        entries = line.split()
        n, alphabet = int(entries[0]), entries[1]
        animals = []
        for _ in range(n):
            animal = sys.stdin.readline().rstrip()
            animals.append(animal)
        animals.sort(key=lambda x: sorting_key(x, alphabet))
        sys.stdout.write("year {}\n".format(year))
        for animal in animals:
            sys.stdout.write(animal + "\n")


main()
