import sys
import string


alphabet = string.digits + string.ascii_lowercase + "0"


def string_to_number(s, base):
    if base == 1 and set(s) == {"1"}:
        return len(s)
    elif base == 1:
        return None
    ret = 0
    for c in s:
        ret *= base
        n = alphabet.index(c)
        if n >= base:
            return None
        ret += n
    return ret


def interpret():
    x, op, y, _, z = sys.stdin.readline().rstrip().split()
    bases = []
    for base in range(1, 37):
        a, b, c = string_to_number(x, base), string_to_number(y, base), string_to_number(z, base)
        if None not in [a, b, c] and max(a, b, c) < 2 ** 32 and\
                ((op == "+" and a + b == c) or (op == "*" and a * b == c)
                 or (op == '-' and a - b == c) or (op == "/" and a / b == c)):
            bases.append(base)
    if bases:
        print("".join(alphabet[base] for base in bases))
    else:
        print("invalid")


def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        interpret()


main()
