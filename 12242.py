import sys
import math
import fractions


def is_power_of_two(n):
    return n != 0 and n & (n - 1) == 0


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        f = fractions.Fraction(sys.stdin.readline().rstrip())
        if not is_power_of_two(f.denominator):
            print(f"Case #{a0}: impossible")
            continue
        cmp = fractions.Fraction(1)
        count = 0
        while cmp > f:
            count += 1
            cmp /= 2
        print(f"Case #{a0}: {count}")


main()
