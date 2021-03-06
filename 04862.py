import sys


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


def main():
    while True:
        a = int(sys.stdin.readline())
        if a == 0:
            break
        b = int(sys.stdin.readline())
        n = int(sys.stdin.readline())
        a1, a2 = a, a
        if a % 2 == 0:
            for i in range(1, b):
                if a1 >= 7:
                    a1 = 0
                    break
                a1 = exp(a % 2 ** 7, a1)
        else:
            for i in range(1, b):
                a1 = expmod(a % 2 ** 7, a1 % 2 ** 6, 10 ** 7)
        if a % 5 == 0:
            for i in range(1, b):
                if a2 >= 7:
                    a2 = 0
                    break
                a2 = exp(a % 5 ** 7, a2)
        else:
            for i in range(1, b):
                a2 = expmod(a % 5 ** 7, a2 % (4 * 5 ** 6), 10 ** 7)
        ans = (a1 * 37 * 5 ** 7 + a2 * 55542 * 2 ** 7) % 10 ** n
        print(str(ans).zfill(n))


main()
