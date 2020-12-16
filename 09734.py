import sys
import math


def add_fractions(a, b, c, d):
    numerator, denominator = a * d + b * c, b * d
    g = math.gcd(numerator, denominator)
    return numerator // g, denominator // g


def main():
    for line in sys.stdin.readlines():
        number = line.rstrip()
        if "." not in number:
            number += ".0"
        integer, decimal = number.split(".")
        numerator, denominator = int(integer), 1
        if "(" in decimal:
            parts = decimal.split("(")
            if parts[0]:
                numerator1, denominator1 = int(parts[0]), 10 ** len(parts[0])
                parts[1] = parts[1][:-1]
                numerator2, denominator2 = int(parts[1]), 10 ** len(parts[0]) * (10 ** len(parts[1]) - 1)
                numerator, denominator = add_fractions(numerator, denominator, numerator1, denominator1)
                numerator, denominator = add_fractions(numerator, denominator, numerator2, denominator2)
            else:
                parts[1] = parts[1][:-1]
                numerator2, denominator2 = int(parts[1]), 10 ** len(parts[1]) - 1
                numerator, denominator = add_fractions(numerator, denominator, numerator2, denominator2)
        else:
            numerator1, denominator1 = int(decimal), 10 ** len(decimal)
            numerator, denominator = add_fractions(numerator, denominator, numerator1, denominator1)
        sys.stdout.write("{} = {} / {}\n".format(number, numerator, denominator))


main()
