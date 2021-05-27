import sys
import fractions


def axby(a, b, y, s):
    ret = 0
    for yi in y:
        servings = yi // s
        if yi % s != 0:
            servings += 1
        if servings >= 4:
            return 10 ** 18
        remaining = s * servings - yi
        ret += a * remaining + b * 6 * servings
    return ret


def main():
    while True:
        n = int(sys.stdin.readline())
        if n == 0:
            break
        a, b = (int(x) for x in sys.stdin.readline().split())
        y = [6 * int(x) for x in sys.stdin.readline().split()]
        ans = 10 ** 18
        for yi in y:
            for k in range(1, 4):
                s = yi // k
                ans = min(ans, axby(a, b, y, s))
        ans = fractions.Fraction(ans, 6)
        if ans.denominator == 1:
            print(ans)
        else:
            print(f"{ans.numerator} / {ans.denominator}")


main()
