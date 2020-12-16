import sys


def primes(limit):
    is_prime = [True] * (limit + 1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(4, limit + 1, 2):
        is_prime[i] = False
    for p in range(3, int(limit ** 0.5) + 1, 2):
        for i in range(2 * p, limit + 1, p):
            is_prime[i] = False
    return [x for x in range(limit+ 1) if is_prime[x]]


def key(all_primes, n):
    factors = []
    for p in all_primes:
        if n % p == 0:
            factors.append(p)
            while n % p == 0:
                n //= p
        if n == 1:
            break
    return 2 * factors[-1] - sum(factors)


def main():
    all_primes = primes(10 ** 6)
    while True:
        a, b = (int(x) for x in sys.stdin.readline().split())
        if a == b == 0:
            break
        if key(all_primes, a) > key(all_primes, b):
            sys.stdout.write("a\n")
        else:
            sys.stdout.write("b\n")


main()
