import sys
import string


def invert_caps(x):
    ret = ""
    for c in x:
        if c.isupper():
            ret += c.lower()
        elif c.islower():
            ret += c.upper()
        else:
            ret += c
    return ret


def strip_nums(x):
    return "".join(c for c in x if c not in string.digits)


def main():
    n = int(sys.stdin.readline())
    for a0 in range(1, n + 1):
        print("Case {}:".format(a0), end=" ")
        original, user = sys.stdin.readline().rstrip().split()
        if original == user:
            print("Login successful.")
            continue
        print("Wrong password.", end=" ")
        if invert_caps(original) == user:
            print("Please, check your caps lock key.", end="")
        elif strip_nums(original) == user:
            print("Please, check your num lock key.", end="")
        elif invert_caps(strip_nums(original)) == user:
            print("Please, check your caps lock and num lock keys.", end="")
        print()


main()
