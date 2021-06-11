import sys


def erathosthenes_sieve(limit):
    is_prime = [True for _ in range(limit + 1)]
    is_prime[0] = False
    is_prime[1] = False
    for i in range(4, limit + 1, 2):
        is_prime[i] = False
    for p in range(3, int(limit ** 0.5) + 1, 2):
        for i in range(3 * p, limit + 1, 2 * p):
            is_prime[i] = False
    return [x for x in range(limit + 1) if is_prime[x]]


def main():
    primes = erathosthenes_sieve(10 ** 7)
    primes_set = set(primes)
    preprocess = [set() for _ in range(10 ** 4 + 1)]
    for n in range(1, 10 ** 4 + 1):
        rolling_sum = sum(primes[:n])
        if rolling_sum in primes_set:
            preprocess[n].add(rolling_sum)
        for i in range(n, len(primes)):
            rolling_sum += primes[i] - primes[i - n]
            if rolling_sum >= 10 ** 7:
                break
            if rolling_sum in primes_set:
                preprocess[n].add(rolling_sum)
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        m = int(sys.stdin.readline())
        nis = [int(x) for x in sys.stdin.readline().split()]
        candidates = primes_set.copy()
        for j in range(m):
            candidates &= preprocess[nis[j]]
        print(f"Scenario {a0}:\n{min(candidates)}\n")


main()
