import sys

DIV = [2, 325, 9375, 28178, 450775, 9780504, 1795265022]


def power(b, e, mod):
    if e == 0:
        return 1
    elif e % 2 == 0:
        x = power(b, e // 2, mod)
        return x * x % mod
    else:
        x = power(b, e // 2, mod)
        return x * x * b % mod


def miller_rabin(n, b):
    if b % n == 0:
        return True
    d = n - 1
    while True:
        if power(b, d, n) == n - 1:
            return True
        if d % 2 == 1:
            break
        d //= 2
    return power(b, d, n) in [1, n - 1]


def is_prime(n):
    if n == 1:
        return False
    elif n == 2:
        return True
    '''
    elif n <= 10 ** 10:
        for p in range(2, int(n ** 0.5) + 1):
            if n % p == 0:
                return False
        return True
    '''
    for divisor in DIV:
        if not miller_rabin(n, divisor):
            return False
    return True


def upside_down(n):
    ret = 0
    while n:
        ret *= 10
        if n % 10 in [0, 1, 2, 5, 8]:
            ret += n % 10
        elif n % 10 in [6, 9]:
            ret += 15 - n % 10
        else:
            return False
        n //= 10
    return ret


def main():
    n = int(sys.stdin.readline())
    m = upside_down(n)
    if not m:
        print("no")
        return
    if is_prime(n) and is_prime(m):
        print("yes")
    else:
        print("no")


main()
