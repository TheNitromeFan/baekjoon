import math
import sys


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        r, c = (int(x) for x in sys.stdin.readline().split())
        sys.stdout.write("Case #{}: {}\n".format(a0, math.comb(r - 1 + c - 1, r - 1)))


main()
