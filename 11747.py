import sys


def smallest(number):
    n = 0
    while True:
        m = str(n)
        if m not in number:
            return m
        n += 1


def main():
    sys.stdin.readline()
    number = ""
    for line in sys.stdin.readlines():
        number += line.rstrip().replace(" ", "")
    sys.stdout.write(smallest(number))


main()
