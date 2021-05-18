import sys


def f(n):
    ret = n
    for k in range(1, 100000):
        if n < 2 ** k:
            break
        ret += 2 ** (k - 1) * (n // 2 ** k)
    return ret


def main():
    a, b = (int(x) for x in sys.stdin.readline().split())
    print(f(b) - f(a - 1))


main()
