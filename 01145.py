from math import gcd
from itertools import combinations


def lcm(a, b):
    return a * b // gcd(a, b)


def main():
    integers = [int(x) for x in input().split()]
    min_lcm_3 = 100 * 99 * 98 * 97 * 96
    for a, b, c in combinations(integers, 3):
        cmp = lcm(lcm(a, b), c)
        if cmp < min_lcm_3:
            min_lcm_3 = cmp
    print(min_lcm_3)


main()
