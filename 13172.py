import sys


def extended_gcd(a, b):
    if b == 0:
        return a, 1, 0
    else:
        g, x, y = extended_gcd(b, a % b)
        return g, y, x - a // b * y


def main():
    p = 10 ** 9 + 7
    m = int(sys.stdin.readline())
    ans = 0
    for _ in range(m):
        a, b = (int(x) for x in sys.stdin.readline().split())
        ans += b * extended_gcd(a, p)[1]
        ans %= p
    print(ans)


main()
