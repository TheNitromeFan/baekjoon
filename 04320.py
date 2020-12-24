import sys
import math


def prime_factors(n):
    ret = {}
    for p in range(2, int(n ** 0.5) + 1):
        if n % p == 0:
            ret[p] = 0
            while n % p == 0:
                n //= p
                ret[p] += 1
    if n > 1:
        ret[n] = 1
    return ret


def main():
    while True:
        n = int(sys.stdin.readline())
        negative = False
        if n == 0:
            break
        elif n < 0:
            negative = True
            n *= -1
        primes = prime_factors(n)
        exponent = 0
        for val in primes.values():
            exponent = math.gcd(exponent, val)
        if negative:
            while exponent % 2 == 0:
                exponent //= 2
        print(exponent)


main()
