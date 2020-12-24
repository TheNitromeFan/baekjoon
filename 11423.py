import sys


def eratosthenes(limit):
    is_prime = [True] * (limit + 1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(4, limit + 1, 2):
        is_prime[i] = False
    for p in range(3, int(limit ** 0.5) + 1, 2):
        for i in range(p * p, limit + 1, p):
            is_prime[i] = False
    return [x for x in range(limit + 1) if is_prime[x]]


def main():
    primes = eratosthenes(10 ** 7)
    for line in sys.stdin.readlines():
        line = line.rstrip()
        if not line:
            continue
        m, n = (int(x) for x in line.split())
        print(len([prime for prime in primes if m <= prime <= n]))
        print()


main()
