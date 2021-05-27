import sys
import math


def comb(n, r, p):
    ret = 1
    while n or r:
        ret *= math.comb(n % p, r % p)
        ret %= p
        n, r = n // p, r // p
    return ret


def main():
    n, m, k, p = (int(x) for x in sys.stdin.readline().split())
    if n or m:
        ans = 0
        for j in range(max(0, (k - n) // 2), k // 2 + 1):
            ans += comb(n, k - 2 * j, p) * comb(n + m + j - 1, j, p)
            ans %= p
        print(ans)
    else:
        print(int(k == 0))


main()
