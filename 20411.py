import sys


def extended_gcd(a, b):
    if b == 0:
        return 1, 0, a
    x, y, g = extended_gcd(b, a % b)
    return y, x - a // b * y, g


def main():
    m, seed, x1, x2 = (int(x) for x in sys.stdin.readline().split())
    a, _, _ = extended_gcd(seed - x1, m)
    a = a * (x1 - x2) % m
    c = (x1 - a * seed) % m
    print(a, c)


main()
