def extended_gcd(a, b):
    x0, x1, y0, y1 = 0, 1, 1, 0
    while a:
        (q, a), b = divmod(b, a), a
        y0, y1 = y1, y0 - q * y1
        x0, x1 = x1, x0 - q * x1
    return b, x0, y0


def main():
    n, a = (int(x) for x in input().split())
    b = n - a
    g, x, y = extended_gcd(n, a)
    if g != 1:
        y = -1
    else:
        while y < 0:
            y += n
        while y > n:
            y -= n
    print("{} {}".format(b, y))


main()
