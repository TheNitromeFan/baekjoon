import sys
import string


def parse(word):
    ret = ""
    for c in word:
        if c in "um":
            ret += c
        elif c in string.ascii_letters + string.digits:
            return None
    return ret


def main():
    s = sys.stdin.readline().rstrip()
    umm = ""
    for word in s.split():
        parsed = parse(word)
        if parsed:
            umm += parsed
    m = len(umm)
    for i in range(0, m, 7):
        code = int(umm[i:i + 7].replace("u", "1").replace("m", "0"), base=2)
        print(chr(code), end="")


main()
