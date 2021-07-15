import sys
import string


def meow_factor(s):
    if "meow" in s:
        return 0
    elif "meo" in s or "eow" in s or "mow" in s or "moew" in s or "mew" in s:
        return 1
    for c in string.ascii_lowercase:
        if "me" + c + "ow" in s or "m" + c + "ow" in s or "me" + c + "w" in s:
            return 1
    if "me" in s or "mo" in s or "mw" in s or "eo" in s or "ew" in s or "ow" in s:
        return 2
    for c in string.ascii_lowercase:
        if "m" + c + "o" in s or "e" + c + "w" in s or "m" + c + "w" in s:
            return 2
    for c in string.ascii_lowercase:
        for d in string.ascii_lowercase:
            if "m" + c + d + "w" in s or "m" + c + "o" + d + "w" in s or "m" + c + "e" + d + "w" in s:
                return 2
    if "m" in s or "e" in s or "o" in s or "w" in s:
        return 3
    return 4


def main():
    s = sys.stdin.readline().rstrip()
    print(meow_factor(s))


main()

