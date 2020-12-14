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


def prime_factors(n):
    ret = []
    for p in range(2, int(n ** 0.5) + 1):
        while n % p == 0:
            ret.append(p)
            n //= p
    if n > 1:
        ret.append(n)
    return ret


def main():
    primes_list = primes(10 ** 5 + 1)
    primes_count = {x: 0 for x in primes_list}
    # print(prime_factors(2))
    n = int(sys.stdin.readline())
    expression = sys.stdin.readline().rstrip().split()
    m = abs(int(expression[0]))
    if m == 0:
        sys.stdout.write("mint chocolate")
        return
    for prime in prime_factors(m):
        primes_count[prime] += 1
    for i in range(2, 2 * n, 2):
        m = abs(int(expression[i]))
        if m == 0:
            sys.stdout.write("mint chocolate")
            return
        pf = prime_factors(m)
        # print(pf)
        if expression[i - 1] == "*":
            for prime in pf:
                primes_count[prime] += 1
        else:
            for prime in pf:
                primes_count[prime] -= 1
        # print(primes_count)
    if all(val >= 0 for val in primes_count.values()):
        sys.stdout.write("mint chocolate")
    else:
        sys.stdout.write("toothpaste")


main()
