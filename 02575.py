import sys


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
    n = int(sys.stdin.readline())
    ans1 = (n - 1) // 3 + 1
    primes = prime_factors(n)
    twos = primes.count(2)
    if n == 1:
        ans2 = 1
    else:
        ans2 = len(primes) - twos // 2
    print(ans1, ans2)


main()
