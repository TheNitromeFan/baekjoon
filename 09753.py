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
    return [x for x in range(limit + 1) if is_prime[x]]


def main():
    single_primes = primes(10 ** 5)
    double_primes = {100001}
    for i, prime1 in enumerate(single_primes):
        for j, prime2 in enumerate(single_primes):
            if j == i or prime1 * prime2 > 10 ** 5:
                break
            double_primes.add(prime1 * prime2)
    t = int(sys.stdin.readline())
    for _ in range(t):
        k = int(sys.stdin.readline())
        while k not in double_primes:
            k += 1
        print(k)


main()
