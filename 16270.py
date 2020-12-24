import sys
import itertools


def prod(list1):
    ret = 1
    for x in list1:
        ret *= x
    return ret


def odd_power_prime_factors(n):
    ret = []
    for p in range(2, int(n ** 0.5) + 1):
        cnt = 0
        while n % p == 0:
            cnt += 1
            n //= p
        if cnt % 2 == 1:
            ret.append(p)
    if n > 1:
        ret.append(n)
    return ret


def combine_primes(primes1, primes2):
    ret = []
    n, m = len(primes1), len(primes2)
    i, j = 0, 0
    while i < n or j < m:
        if i == n:
            ret.append(primes2[j])
            j += 1
        elif j == m:
            ret.append(primes1[i])
            i += 1
        elif primes1[i] == primes2[j]:
            i += 1
            j += 1
        elif primes1[i] < primes2[j]:
            ret.append(primes1[i])
            i += 1
        else:
            ret.append(primes2[j])
            j += 1
    return ret


def minimum_sum_split(primes):
    ret1, ret2 = 1, prod(primes)
    n = len(primes)
    for m in range(2 ** n):
        a, b = 1, 1
        k = m
        for i in range(n):
            if k % 2 == 0:
                a *= primes[i]
            else:
                b *= primes[i]
            k //= 2
        if a + b < ret1 + ret2:
            ret1, ret2 = a, b
    return ret1, ret2


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        a, b = (int(x) for x in sys.stdin.readline().split())
        primes1, primes2 = odd_power_prime_factors(a), odd_power_prime_factors(b)
        primes = combine_primes(primes1, primes2)
        ans1, ans2 = minimum_sum_split(primes)
        print(ans1, ans2)


main()
