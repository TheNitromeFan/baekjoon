import sys
import math


def bet(r, s, x, y, w):
    running_sum = 0
    for k in range(x, y + 1):
        term = math.comb(y, k) * (s - r + 1) ** k * (r - 1) ** (y - k) * w
        running_sum += term
    return running_sum - s ** y > 0


def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        r, s, x, y, w = (int(z) for z in sys.stdin.readline().split())
        if bet(r, s, x, y, w):
            sys.stdout.write("yes\n")
        else:
            sys.stdout.write("no\n")


main()
