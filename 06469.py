import sys
import math


def right_justified(x):
    y = str(x)
    return " " * (10 - len(y)) + y


def main():
    for line in sys.stdin:
        step, mod = (int(x) for x in line.rstrip().split())
        if math.gcd(step, mod) == 1:
            print("{}{} Good Choice\n".format(right_justified(step), right_justified(mod)))
        else:
            print("{}{} Bad Choice\n".format(right_justified(step), right_justified(mod)))


main()
