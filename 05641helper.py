import sys


def apparent_prime(n, primes):
    for prime in primes:
        if n % prime == 0:
            return False
    return True


def erathosthenes_sieve(limit):
    is_prime = [True for _ in range(limit + 1)]
    is_prime[0] = False
    is_prime[1] = False
    for i in range(4, limit + 1, 2):
        is_prime[i] = False
    for p in range(3, int(limit ** 0.5) + 1, 2):
        for i in range(p * p, limit + 1, 2 * p):
            is_prime[i] = False
    return [x for x in range(limit + 1) if is_prime[x]]


def main():
    primes = erathosthenes_sieve(8000)
    d = {}
    for n in range(3500, 5001):
        ans = 10 ** (n - 1) + 1
        while not (apparent_prime(ans, primes) and apparent_prime(ans + 2, primes)):
            ans += 2
        d[n] = ans - 10 ** (n - 1)
        print(n)
    print(d)


main()
