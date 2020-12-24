import sys


def main():
    n = int(sys.stdin.readline())
    levels = [int(x) for x in sys.stdin.readline().split()]
    print(sum(levels) + (n - 2) * max(levels))


main()
