import sys


def main():
    n = int(sys.stdin.readline())
    heroes = [int(x) for x in sys.stdin.readline().split()]
    villains = [int(x) for x in sys.stdin.readline().split()]
    days = 0
    while heroes < villains:
        days += 1
        for i in range(n):
            heroes[i] += 1
    print(days)


main()
