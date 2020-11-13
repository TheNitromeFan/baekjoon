import sys


def is_prime(n):
    for p in range(2, int(n ** 0.5) + 1):
        if n % p == 0:
            return False
    return True


def main():
    while True:
        n = int(sys.stdin.readline())
        if n == 0:
            break
        print("{} = ".format(n), end="")
        summands = []
        primes = []
        p = 2
        while n:
            if not is_prime(p):
                p += 1
                continue
            if n % p:
                summands.append("*".join(str(x) for x in [n % p] + primes))
            n //= p
            primes.append(p)
            p += 1
        print(" + ".join(summands))


main()
