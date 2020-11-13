import sys
import math


def add_fractions(n1, d1, n2, d2):
    n, d = n1 * d2 + n2 * d1, d1 * d2
    g = math.gcd(n, d)
    return n // g, d // g


def main():
    test = 0
    while True:
        m = int(sys.stdin.readline())
        if m == 0:
            break
        test += 1
        n, d = 0, 1
        for i in range(1, m+1):
            line = sys.stdin.readline().rstrip()
            if "," in line:
                w, frac = line.split(",")
                n1, d1 = (int(x) for x in frac.split("/"))
                n1 += int(w) * d1
            elif "/" in line:
                n1, d1 = (int(x) for x in line.split("/"))
            else:
                n1, d1 = int(line), 1
            n, d = add_fractions(n, d, n1, d1)
        if n % d == 0:
            print("Test {}: {}".format(test, n // d))
        elif n > d:
            print("Test {}: {},{}/{}".format(test, n // d, n % d, d))
        else:
            print("Test {}: {}/{}".format(test, n, d))


main()
