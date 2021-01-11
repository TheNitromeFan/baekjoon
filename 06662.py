import sys


def generate_primes(limit):
    is_prime = [True] * (limit + 1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(4, limit + 1, 2):
        is_prime[i] = False
    for p in range(3, int(limit ** 0.5) + 1, 2):
        for i in range(p * p, limit + 1, 2 * p):
            is_prime[i] = False
    return [x for x in range(limit + 1) if is_prime[x]]


def legendre(n, prime):
    ret = 0
    while n >= prime:
        ret += n // prime
        n //= prime
    return ret


def main():
    primes = generate_primes(500)
    dp = {}
    for n in range(500):
        for prime in primes:
            dp[(n, prime)] = legendre(n, prime)
    for line in sys.stdin.readlines():
        n, k = (int(x) for x in line.split())
        ans = 1
        for prime in primes:
            ans *= dp[(n, prime)] - dp[(k, prime)] - dp[(n - k, prime)] + 1
        print(ans)


main()
