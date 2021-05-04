import sys
import string


DIGITS = string.digits + string.ascii_lowercase


def convert_to_decimal(num, base):
    ret = 0
    for digit in num:
        ret *= base
        ret += DIGITS.index(digit)
    return ret


def main():
    a, b = sys.stdin.readline().rstrip().split()
    if a == b == "0":
        print("Multiple")
        return
    elif a == "0" or b == "0":
        print("Impossible")
        return
    answers = []
    for base1 in range(2, 37):
        if any(DIGITS.index(c) >= base1 for c in a):
            continue
        for base2 in range(2, 37):
            if base2 == base1 or any(DIGITS.index(c) >= base2 for c in b):
                continue
            x = convert_to_decimal(a, base1)
            if x == convert_to_decimal(b, base2) < 2 ** 63:
                answers.append((x, base1, base2))
                if len(answers) > 1:
                    print("Multiple")
                    return
    if answers:
        print(*answers[0])
    else:
        print("Impossible")



main()
