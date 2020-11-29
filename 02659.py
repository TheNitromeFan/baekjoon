import sys
import string
import itertools


def main():
    cross_numbers = set()
    for a, b, c, d in itertools.product(string.digits[1:], repeat=4):
        a, b, c, d = int(a), int(b), int(c), int(d)
        cross_numbers.add(min(1000 * a + 100 * b + 10 * c + d, 1000 * b + 100 * c + 10 * d + a,
                              1000 * c + 100 * d + 10 * a + b, 1000 * d + 100 * a + 10 * b + c))
    x, y, z, w = (int(f) for f in sys.stdin.readline().split())
    cross_number = min(1000 * x + 100 * y + 10 * z + w, 1000 * y + 100 * z + 10 * w + x,
                       1000 * z + 100 * w + 10 * x + y, 1000 * w + 100 * x + 10 * y + z)
    sys.stdout.write("{}".format(len([g for g in cross_numbers if g <= cross_number])))


main()
