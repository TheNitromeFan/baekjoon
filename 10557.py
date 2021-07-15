import sys
import string


def evaluate(line):
    left, right = line.split("=")
    if "+" in left:
        idx = left.find("+")
        a, b = left[:idx], left[idx + 1:]
        if (len(a) >= 2 and (a[0] == "0" or (a[0] == "-" and a[1] == "0"))) or \
                (len(b) >= 2 and (b[0] == "0" or (b[0] == "-" and b[1] == "0"))) or \
                (len(right) >= 2 and (right[0] == "0" or (right[0] == "-" and right[1] == "0"))):
            return False
        return int(a) + int(b) == int(right)
    elif "*" in left:
        idx = left.find("*")
        a, b = left[:idx], left[idx + 1:]
        if (len(a) >= 2 and (a[0] == "0" or (a[0] == "-" and a[1] == "0"))) or \
                (len(b) >= 2 and (b[0] == "0" or (b[0] == "-" and b[1] == "0"))) or \
                (len(right) >= 2 and (right[0] == "0" or (right[0] == "-" and right[1] == "0"))):
            return False
        return int(a) * int(b) == int(right)
    else:
        idx = left[1:].find("-") + 1
        a, b = left[:idx], left[idx + 1:]
        if (len(a) >= 2 and (a[0] == "0" or (a[0] == "-" and a[1] == "0"))) or \
                (len(b) >= 2 and (b[0] == "0" or (b[0] == "-" and b[1] == "0"))) or \
                (len(right) >= 2 and (right[0] == "0" or (right[0] == "-" and right[1] == "0"))):
            return False
        return int(a) - int(b) == int(right)


def find_rune(runes):
    for c in string.digits:
        if c in runes:
            continue
        line = runes.replace("?", c)
        if evaluate(line):
            return c
    return "-1"


def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        runes = sys.stdin.readline().rstrip()
        sys.stdout.write(find_rune(runes) + "\n")


main()
