import sys


def parse(ucn):
    digits = "0123456789ACDEFHJKLMNPRTVWX"
    to_replace = {"B": "8", "G": "C", "I": "1", "O": "0", "Q": "0", "S": "5", "U": "V", "Y": "V", "Z": "2"}
    for key, val in to_replace.items():
        ucn = ucn.replace(key, val)
    multiples = [2, 4, 5, 7, 8, 10, 11, 13]
    value = 0
    check_digit = 0
    for i, char in enumerate(ucn[:-1]):
        value = value * 27 + digits.index(char)
        check_digit += multiples[i] * digits.index(char)
    if check_digit % 27 == digits.index(ucn[8]):
        return value
    else:
        return "Invalid"


def main():
    p = int(sys.stdin.readline())
    for _ in range(p):
        k, ucn = sys.stdin.readline().rstrip().split()
        sys.stdout.write("{} {}\n".format(k, parse(ucn)))


main()
