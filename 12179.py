import math
import sys


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        d = int(sys.stdin.readline())
        if d <= 4:
            sys.stdout.write("Case #{}: ...\n".format(a0))
        for inc in range(1, 9000):
            multifact = 1
            for n in range(9000, 0, -inc):
                multifact *= n
            if int(math.log10(multifact)) + 1 < d:
                sys.stdout.write("Case #{}: IT'S OVER 9000{}\n".format(a0, "!" * inc))
                break


main()
