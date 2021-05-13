import sys
import fractions


def cantor(a, b, f, n):
    if n == 10:
        return -1
    elif a <= f <= (2 * a + b) / 3:
        return cantor(a, (2 * a + b) / 3, f, n + 1)
    elif (a + 2 * b) / 3 <= f <= b:
        return cantor((a + 2 * b) / 3, b, f, n + 1)
    elif a <= f <= b:
        return n + 1
    else:
        return n


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        a, b = (int(x) for x in sys.stdin.readline().split())
        f = fractions.Fraction(a, b)
        print(cantor(fractions.Fraction(0), fractions.Fraction(1), f, 0))


main()
