import sys
import math


def add_fractions(a, b, c, d):
    numerator, denominator = a * d + b * c, b * d
    g = math.gcd(numerator, denominator)
    return numerator // g, denominator // g


def main():
    n = int(sys.stdin.readline())
    numerator, denominator = 0, 1
    for i in range(1, n + 1):
        numerator, denominator = add_fractions(numerator, denominator, 1, i)
    sys.stdout.write("{}\n{}".format(numerator, denominator))


main()
