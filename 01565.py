import sys
import math


gcd = math.gcd


def lcm(a, b):
    return a // gcd(a, b) * b


def divisors(x):
    ret = 1
    for p in range(2, int(x ** 0.5) + 1):
        cnt = 0
        while x % p == 0:
            cnt += 1
            x //= p
        ret *= cnt + 1
    if x > 1:
        ret *= 2
    return ret


def main():
    a, b = (int(x) for x in sys.stdin.readline().split())
    d = [int(x) for x in sys.stdin.readline().split()]
    m = [int(x) for x in sys.stdin.readline().split()]
    low = 1
    for di in d:
        low = lcm(low, di)
    high = 0
    for mj in m:
        high = gcd(high, mj)
    if high % low != 0:
        print(0)
        return
    print(divisors(high // low))


main()
