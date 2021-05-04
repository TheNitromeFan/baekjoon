import sys
import fractions


def main():
    n = int(sys.stdin.readline())
    d = int(sys.stdin.readline())
    binary = sys.stdin.readline().rstrip()
    pa = fractions.Fraction(d, 8)
    num = fractions.Fraction(0, 1)
    for c, bit in enumerate(binary[2:], start=1):
        if bit == "1":
            num += fractions.Fraction(1, 2 ** c)
    a, b = fractions.Fraction(0, 1), fractions.Fraction(1, 1)
    for _ in range(n):
        c = a + pa * (b - a)
        if num < c:
            sys.stdout.write("A")
            b = c
        else:
            sys.stdout.write("B")
            a = c


main()
