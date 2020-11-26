import math
import sys


def combination(n, r):
    return math.factorial(n) // math.factorial(r) // math.factorial(n - r)


def passes(m, n):
    ret = 0
    for k in range(m + 1):
        ret += (-1) ** k * combination(m, k) * (m - k) ** n
    return ret


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        m, n = (int(x) for x in sys.stdin.readline().split())
        sys.stdout.write("Case #{}: {}\n".format(a0, passes(m, n) % (10 ** 9 + 7)))


main()
