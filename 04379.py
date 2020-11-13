import sys


MAX = 10 ** 99


def quotient(t, a, b):
    if t == 1 or a % b:
        return "is not an integer with less than 100 digits."
    tb = 1
    for _ in range(b):
        tb *= t
        if tb >= MAX:
            break
    ntb = 1
    s = 0
    for _ in range(0, a, b):
        s += ntb
        if s >= MAX:
            return "is not an integer with less than 100 digits."
        ntb *= tb
    if s >= MAX:
        return "is not an integer with less than 100 digits."
    else:
        return s


def main():
    for line in sys.stdin:
        t, a, b = (int(x) for x in line.split())
        print("({}^{}-1)/({}^{}-1) {}".format(t, a, t, b, quotient(t, a, b)))


main()
