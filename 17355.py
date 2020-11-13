import math


MOD = 10 ** 9 + 7


def main():
    n = int(input())
    num, den = 1, 1
    for _ in range(n):
        a, b = (int(x) for x in input().split())
        num *= b - a
        den *= b
    g = math.gcd(num, den)
    print("{} {}".format((num // g) % MOD, (den // g) % MOD))


main()
