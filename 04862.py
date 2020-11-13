import sys


def f(b, x, mod):
    if x == 0:
        return 1
    else:
        exp = f(b, x - 1, mod)
        return b ** (exp % (4 * mod))


def main():
    while True:
        b = int(sys.stdin.readline())
        if b == 0:
            break
        i = int(sys.stdin.readline())
        n = int(sys.stdin.readline())
        print(str(f(b, i, 10 ** n)).zfill(n))


main()
