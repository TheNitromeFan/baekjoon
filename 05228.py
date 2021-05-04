import sys
import string


DIGITS = string.digits + string.ascii_lowercase


def convert_base(n, k):
    if n == 0:
        return "0"
    ret = ""
    while n:
        ret = DIGITS[n % k] + ret
        n //= k
    return ret


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        n, k = (int(x) for x in sys.stdin.readline().split())
        m = convert_base(n, k)
        sys.stdout.write(f"Base-{k} representation of {n} is {m}; ")
        if all(digit in m for digit in DIGITS[:k]):
            sys.stdout.write("contains all digits.\n")
        else:
            sys.stdout.write("does not contain all digits.\n")


main()
