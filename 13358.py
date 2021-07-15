def expmod(base, e, mod):
    if e == 0:
        return 1
    elif e % 2 == 0:
        x = expmod(base, e // 2, mod)
        return x * x % mod
    else:
        x = expmod(base, e // 2, mod)
        return x * x * base % mod


def tot(n):
    r = p = 1
    while n > 1:
        p += (p*p < n) or (n-p)
        x = 1
        while n % p == 0:
            n //= p
            r *= p - x
            x = 0
    return r


def naive(n, m):
    if n == 1:
        return 1
    return expmod(n, naive(n - 1, m), m)


def tetration_mod(n, m):
    if m == 1:
        return 1
    if n <= 5:
        return naive(n, m)
    return expmod(n, tetration_mod(n - 1, tot(m)) + tot(m), m)


def main():
    n, m = (int(x) for x in input().split())
    print(tetration_mod(n, m) % m)


main()
