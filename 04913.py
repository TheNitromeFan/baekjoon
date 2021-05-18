import sys


def erathosthenes_sieve(n):
    is_prime = [True for _ in range(n + 1)]
    is_prime[0] = False
    is_prime[1] = False
    for i in range(4, n + 1, 2):
        is_prime[i] = False
    for p in range(3, int(n ** 0.5) + 1, 2):
        for i in range(3 * p, n + 1, 2 * p):
            is_prime[i] = False
    return [x for x in range(n + 1) if is_prime[x]]


def main():
    primes = erathosthenes_sieve(10 ** 6)
    while True:
        lower, upper = (int(x) for x in sys.stdin.readline().split())
        if lower == upper == -1:
            break
        ans1 = sum(1 for x in primes if lower <= x <= upper)
        ans2 = sum(1 for x in primes if lower <= x <= upper and x % 4 == 1)
        if lower <= 2 <= upper:
            ans2 += 1
        print(f"{lower} {upper} {ans1} {ans2}")


main()
