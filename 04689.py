import sys


display = "0123456789ABCDEF"


def convert(string, old_base, new_base):
    n = int(string, old_base)
    ret = ""
    while n:
        ret = display[n % new_base] + ret
        n //= new_base
    if len(ret) > 7:
        return "  ERROR"
    else:
        return " " * (7 - len(ret)) + ret


def main():
    for line in sys.stdin.readlines():
        string, old_base, new_base = line.rstrip().split()
        old_base, new_base = int(old_base), int(new_base)
        print(convert(string, old_base, new_base))


main()
