import sys


def padded(number, length):
    return "0" * (length - len(number)) + number


def is_cyclic(number):
    i, n, cmp = int(number), len(number), sorted(number)
    return all(sorted(padded(str(i * k), n)) == cmp for k in range(1, n+1))


def main():
    for line in sys.stdin:
        number = line.rstrip()
        if is_cyclic(number):
            print("{} is cyclic".format(number))
        else:
            print("{} is not cyclic".format(number))


main()
