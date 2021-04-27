import sys


def generate_primes(limit):
    is_prime = [True] * (limit + 1)
    is_prime[0] = False
    is_prime[1] = False
    for i in range(4, limit + 1, 2):
        is_prime[i] = False
    for p in range(3, int(limit ** 0.5) + 1, 2):
        for i in range(p ** 2, limit + 1, 2 * p):
            is_prime[i] = False
    return [str(x) for x in range(limit + 1) if is_prime[x]]


def main():
    primes = generate_primes(10 ** 5)
    while True:
        n = sys.stdin.readline().rstrip()
        if n == "0":
            break
        for prime in primes[::-1]:
            if prime in n:
                print(prime)
                break


main()
