import sys


def f(n):
    i = 1
    j = 0
    ret = 0
    while i <= n:
        j = n // (n // i)
        ret += (i + j) * (j - i + 1) // 2 * (n // i)
        i = j + 1
    return ret


def main():
    a, b = (int(x) for x in sys.stdin.readline().split())
    print(f(b) - f(a - 1))


main()
