import sys


def string_base(n, b):
    if n == 0:
        return "0"
    ret = ""
    while n > 0:
        ret = str(n % b) + ret
        n //= b
    return ret


def main():
    while True:
        line = sys.stdin.readline().rstrip()
        if line == "0":
            break
        entries = line.split()
        b = int(entries[0])
        p = int(entries[1], base=b)
        m = int(entries[2], base=b)
        k = p % m
        print(string_base(k, b))


main()
