import sys
import math


def right_justified(n):
    n = str(n)
    return ' ' * (5-len(n)) + n


def last_nonzero_factorial_digit(n):
    return str(math.factorial(n)).strip('0')[-1:]


def main():
    for line in sys.stdin:
        n = int(line)
        print("{} -> {}".format(right_justified(n), last_nonzero_factorial_digit(n)))


main()
