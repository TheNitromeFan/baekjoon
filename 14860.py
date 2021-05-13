import sys


MOD = 10 ** 9 + 7


def power(base, exp):
    if exp == 0:
        return 1
    elif exp % 2 == 0:
        return power(base * base % MOD, exp // 2)
    else:
        return base * power(base * base % MOD, exp // 2) % MOD


def erathosthenes_sieve(n):
    is_prime = [True] * (n + 1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(4, n + 1, 2):
        is_prime[i] = False
    for p in range(3, int(n ** 0.5) + 1, 2):
        for i in range(3 * p, n + 1, p):
            is_prime[i] = False
    return [x for x in range(n + 1) if is_prime[x]]


def main():
    n, m = (int(x) for x in sys.stdin.readline().split())
    sieve = erathosthenes_sieve(min(n, m))
    ans = 1
    for p in sieve:
        factors = 0
        j = p
        while j <= min(n, m):
            factors += (n // j) * (m // j)
            j *= p
        ans *= power(p, factors)
        ans %= MOD
    print(ans)


main()
