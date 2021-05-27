import sys
import math


def lucas(n, m, p):
    ret = 1
    while n or m:
        ni, mi = n % p, m % p
        ret *= math.comb(ni, mi)
        ret %= p
        n, m = n // p, m // p
    return ret


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        n, m = (int(x) for x in sys.stdin.readline().split())
        if n == 0 and m == 1:
            print(1)
            continue
        elif n == 0 or m == 1:
            print(0)
            continue
        a1, a2 = lucas(n - 1, m - 2, 97), lucas(n - 1, m - 2, 1031)
        print((a1 * 35 * 1031 + a2 * 659 * 97) % (97 * 1031))


main()
