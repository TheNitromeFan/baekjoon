import sys
from decimal import *


def evaluate(c, k, x):
    ret = Decimal(0)
    for i, ci in enumerate(c):
        ret += Decimal(ci) * Decimal(x) ** Decimal(k - i)
    return ret


def main():
    k = int(sys.stdin.readline())
    c = [int(x) for x in sys.stdin.readline().split()]
    a, b, n = (int(x) for x in sys.stdin.readline().split())
    actual = 0
    for i, ci in enumerate(c):
        actual += Decimal(ci) * (Decimal(b) ** Decimal(k - i + 1) - Decimal(a) ** Decimal(k - i + 1)) / \
                  Decimal(k - i + 1)
    delta = Decimal((b - a) / n)
    low, high = Decimal(0), Decimal(b - a) / Decimal(n)
    while True:
        mid = (low + high) / 2
        estimate = 0
        for i in range(n):
            # print(a + i * delta + mid)
            estimate += evaluate(c, k, a + i * delta + mid) * delta
        # print(actual, estimate)
        if abs(estimate - actual) / actual < Decimal(0.00001):
            break
        elif estimate > actual:
            high = mid
        else:
            low = mid
    print(str(mid)[:10])


getcontext().prec = 50
main()
