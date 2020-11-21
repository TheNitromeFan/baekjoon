import sys
import math


def combination(n, r):
    return math.factorial(n) // math.factorial(r) // math.factorial(n - r)


def death(a, b, c):
    min_bombs = (c - 1) // 5 + 1
    if b < min_bombs:
        return 1
    return (combination(a, min_bombs) - combination(b, min_bombs)) / combination(a, min_bombs)


def main():
    a, b, c = (int(x) for x in sys.stdin.readline().split())
    sys.stdout.write("{0:.9f}".format(death(a, b, c)))


main()
