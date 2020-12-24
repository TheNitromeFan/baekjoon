import sys
import fractions


def main():
    for line in sys.stdin.readlines():
        try:
            n = int(line)
        except ValueError:
            continue
        hn = fractions.Fraction(0)
        for i in range(1, n + 1):
            hn += fractions.Fraction(numerator=1, denominator=i)
        hn *= n
        if hn.denominator > 1:
            n, d = hn.numerator, hn.denominator
            m, r = divmod(n, d)
            mm, dd = str(m), str(d)
            print(" " * len(mm), r)
            print(mm, "-" * len(dd))
            print(" " * len(mm), dd)
        else:
            print(hn.numerator)


main()
