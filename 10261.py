import sys
import math


def main():
    n = int(sys.stdin.readline()) + 1
    sys.stdout.write(str(math.comb(2 * n, n) // (n + 1)))


main()
