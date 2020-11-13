MOD = 10 ** 9 + 7


def exp(a, x):
    if x == 0:
        return 1
    elif x % 2 == 0:
        b = exp(a, x // 2)
        return b * b % MOD
    else:
        b = exp(a, x // 2)
        return b * b * a % MOD


def main():
    n = int(input())
    ans = 0
    for _ in range(n):
        c, k = (int(x) for x in input().split())
        if k == 0:
            continue
        ans += c * k * exp(2, k - 1)
        ans %= MOD
    print(ans)


main()
