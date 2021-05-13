import sys


def prime_factors(n):
    ret = set()
    for p in range(2, int(n ** 0.5)):
        if n % p != 0:
            continue
        ret.add(p)
        while n % p == 0:
            n //= p
    if n > 1:
        ret.add(n)
    return ret


def main():
    n = int(sys.stdin.readline())
    a = []
    for _ in range(n):
        a.append(int(sys.stdin.readline()))
    primes = set()
    for ai in a:
        primes |= prime_factors(ai)
    ans = 0
    for prime in primes:
        ans = max(ans, sum(ai for ai in a if ai % prime == 0))
    print(ans)


main()
