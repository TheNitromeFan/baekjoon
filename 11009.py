import sys
import math


def add_frac(a, b, c, d):
    numerator = a * d + b * c
    denominator = b * d
    g = math.gcd(numerator, denominator)
    return numerator // g, denominator // g


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        n, m = (int(x) for x in sys.stdin.readline().split())
        numerator, denominator = n, n + m
        a, b = n, n + m
        for i in range(m, 1, -2):
            a *= i * (i - 1)
            b *= (n + i - 1) * (n + i - 2)
            numerator, denominator = add_frac(numerator, denominator, a, b)
        sys.stdout.write("{}/{}\n".format(numerator, denominator))


main()
