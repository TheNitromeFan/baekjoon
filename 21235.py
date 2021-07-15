import sys


def main():
    zodiac = {"Ox": 0, "Tiger": 1, "Rabbit": 2, "Dragon": 3, "Snake": 4, "Horse": 5, "Goat": 6, "Monkey": 7,
              "Rooster": 8, "Dog": 9, "Pig": 10, "Rat": 11}
    years = {"Bessie": 2400}
    n = int(sys.stdin.readline())
    for _ in range(n):
        words = sys.stdin.readline().rstrip().split()
        year = years[words[-1]]
        if words[3] == "next":
            year += 1
            while year % 12 != zodiac[words[4]]:
                year += 1
            years[words[0]] = year
        else:
            year -= 1
            while year % 12 != zodiac[words[4]]:
                year -= 1
            years[words[0]] = year
    print(abs(years["Bessie"] - years["Elsie"]))


main()
