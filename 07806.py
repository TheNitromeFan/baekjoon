import sys


def prime_tally(n):
    ret = {}
    for p in range(2, int(n ** 0.5) + 1):
        if n % p == 0:
            ret[p] = 0
            while n % p == 0:
                n //= p
                ret[p] += 1
    if n > 1:
        ret[n] = 1
    return ret


def factorial_exponent(n, prime):
    ret = 0
    while n >= prime:
        ret += n // prime
        n //= prime
    return ret


def factorial_gcd(n, k):
    tally = prime_tally(k)
    ret = 1
    for prime, e in tally.items():
        exp = factorial_exponent(n, prime)
        ret *= prime ** min(e, exp)
    return ret


def main():
    for line in sys.stdin.readlines():
        n, k = (int(x) for x in line.split())
        print(factorial_gcd(n, k))


main()
