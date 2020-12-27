import sys


def euclid(a, b, c, d):
    if c == d == 0:
        return a, b
    else:
        p, q = round((a * c + b * d) / (c ** 2 + d ** 2)), round((b * c - a * d) / (c ** 2 + d ** 2))
        return euclid(c, d, a - c * p + d * q, b - d * p - c * q)


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        a, b, c, d = (int(x) for x in sys.stdin.readline().split())
        p, q = euclid(a, b, c, d)
        ans = {(p, q), (-q, p), (-p, -q), (q, -p)}
        print(len(ans))
        for p, q in sorted(ans):
            print(p, q, end=" ")
        print()


main()
