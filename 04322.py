import sys
import fractions


def main():
    while True:
        d = sys.stdin.readline().rstrip()
        if d == "0":
            break
        d = d[:-3]
        ans = (fractions.Fraction(d + d[-1]) * 10 - fractions.Fraction(d)) / 9
        for i in range(2, len(d) - 1):
            cmp = (fractions.Fraction(d + d[-i:]) * 10 ** i - fractions.Fraction(d)) / (10 ** i - 1)
            if ans.denominator > cmp.denominator:
                ans = cmp
        sys.stdout.write("{}/{}\n".format(ans.numerator, ans.denominator))


main()
