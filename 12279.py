import sys


def fraction(n):
    if n == 0:
        return 1, 1
    p, q = fraction((n - 1) // 2)
    if n % 2 == 1:
        return p, p + q
    else:
        return p + q, q


def ordinal(p, q):
    if p == q == 1:
        return 0
    elif p < q:
        return 2 * ordinal(p, q - p) + 1
    else:
        return 2 * ordinal(p - q, q) + 2


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        entries = [int(x) for x in sys.stdin.readline().split()]
        if entries[0] == 1:
            n = entries[1]
            p, q = fraction(n - 1)
            print(f"Case #{a0}: {p} {q}")
        else:
            p, q = entries[1], entries[2]
            n = ordinal(p, q) + 1
            print(f"Case #{a0}: {n}")


main()
