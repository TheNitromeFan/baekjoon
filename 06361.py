import sys
import string


s = string.digits + string.ascii_uppercase + string.ascii_lowercase


def change_base(num, base1, base2):
    n = 0
    for x in num:
        n *= base1
        n += s.index(x)
    ret = ""
    while n:
        ret = s[n % base2] + ret
        n //= base2
    if not ret:
        ret = "0"
    return ret


def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        entries = sys.stdin.readline().rstrip().split()
        base1, base2, num = int(entries[0]), int(entries[1]), entries[2]
        print("{} {}".format(base1, num))
        print("{} {}".format(base2, change_base(num, base1, base2)))
        print()


main()
