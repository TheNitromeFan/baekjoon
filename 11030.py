def exp(base, e):
    if e == 0:
        return 1
    elif e % 2 == 0:
        x = exp(base, e // 2)
        return x * x
    else:
        x = exp(base, e // 2)
        return x * x * base


def expmod(base, e, mod):
    if e == 0:
        return 1
    elif e % 2 == 0:
        x = expmod(base, e // 2, mod)
        return x * x % mod
    else:
        x = expmod(base, e // 2, mod)
        return x * x * base % mod


def zero_pad(a, b):
    x = a
    for _ in range(1, b):
        x = a ** x
        if x >= 10 ** 8:
            return True
    return False


def main():
    a, b = (int(x) for x in input().split())
    if b == 0:
        print(1)
        return
    a1, a2 = a, a
    if a % 2 == 0:
        for i in range(1, b):
            if a1 >= 8:
                a1 = 0
                break
            a1 = exp(a % 2 ** 8, a1)
    else:
        for i in range(1, b):
            a1 = expmod(a % 2 ** 8, a1 % (2 ** 6), 10 ** 8)
    if a % 5 == 0:
        for i in range(1, b):
            if a2 >= 8:
                a2 = 0
                break
            a2 = exp(a % 5 ** 8, a2)
    else:
        for i in range(1, b):
            a2 = expmod(a % 5 ** 8, a2 % (4 * 5 ** 7), 10 ** 8)
    if zero_pad(a, b):
        print(str((a1 * 33 * 5 ** 8 + a2 * (-50354) * 2 ** 8) % 10 ** 8).zfill(8))
    else:
        print(str((a1 * 33 * 5 ** 8 + a2 * (-50354) * 2 ** 8) % 10 ** 8))


main()
