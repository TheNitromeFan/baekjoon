MOD = 10 ** 9 + 7


def exp(a, x):
    if x == 1:
        return a
    elif x % 2 == 0:
        b = exp(a, x // 2)
        return b * b % MOD
    else:
        b = exp(a, x // 2)
        return b * b * a % MOD


def main():
    a = int(input())
    x = int(input())
    a %= MOD
    print(exp(a, x))


main()
