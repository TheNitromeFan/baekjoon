import sys
import decimal


def main():
    entries = sys.stdin.readline().rstrip().split()
    n, t = int(entries[0]), decimal.Decimal(entries[1])
    x = [decimal.Decimal(y) for y in sys.stdin.readline().rstrip().split()]
    v = [decimal.Decimal(y) for y in sys.stdin.readline().rstrip().split()]
    minimum, maximum = x[0] - v[0] * t, x[0] + v[0] * t
    for xi, vi in zip(x, v):
        minimum = max(minimum, xi - vi * t)
        maximum = min(maximum, xi + vi * t)
    print(int(minimum <= maximum))


main()
