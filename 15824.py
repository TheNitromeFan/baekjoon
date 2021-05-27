import sys


MOD = 10 ** 9 + 7


def power(base, exp):
    if exp == 0:
        return 1
    elif exp % 2 == 0:
        return power(base * base % MOD, exp // 2)
    else:
        return power(base * base % MOD, exp // 2) * base % MOD


def main():
    n = int(sys.stdin.readline())
    a = [int(x) for x in sys.stdin.readline().split()]
    a.sort()
    ans = 0
    for ind, val in enumerate(a):
        ans += val * (power(2, ind) - power(2, n - 1 - ind))
        ans %= MOD
    print(ans)


main()
