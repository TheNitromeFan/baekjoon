import sys
import math


def main():
    n = int(sys.stdin.readline())
    fractions = []
    common_denominator = 1
    for _ in range(n):
        a, b = (int(y) for y in sys.stdin.readline().split())
        g = math.gcd(a, b)
        a, b = a // g, b // g
        fractions.append((a, b))
        common_denominator *= b // math.gcd(common_denominator, b)
    numerator = 0
    for a, b in fractions:
        numerator = math.gcd(numerator, a * common_denominator // b)
    g = math.gcd(numerator, common_denominator)
    numerator, common_denominator = numerator // g, common_denominator // g
    print(numerator, common_denominator)


main()
