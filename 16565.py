import sys
import math


def main():
    n = int(sys.stdin.readline())
    ans = 0
    mod = 10007
    for i in range(4, n + 1, 4):
        sign = (-1) ** (i // 4 + 1)
        ans += sign * math.comb(13, i // 4) * math.comb(52 - i, n - i)
        ans %= mod
    print(ans)


main()
