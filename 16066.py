import sys
import math
import decimal


def prime(n):
    if n == 1:
        return False
    for p in range(2, int(n ** 0.5) + 1):
        if n % p == 0:
            return False
    return True


def main():
    decimal.getcontext().prec = 7
    t = int(sys.stdin.readline())
    for _ in range(t):
        a, b = (int(decimal.Decimal(x) * 100000) for x in sys.stdin.readline().split())
        g = math.gcd(a, b)
        a //= g
        b //= g
        if a == 1 and b == 1:
            a *= 2
            b *= 2
        if prime(a) and prime(b):
            print(a, b)
        else:
            print("impossible")


main()
