import sys


def convert_to_ternary(digits, number):
    ret = ""
    while number:
        ret = str(number % 3) + ret
        number //= 3
    return ret.zfill(digits)


def main():
    for line in sys.stdin.readlines():
        n = int(line)
        for i in range(3 ** n):
            ternary = convert_to_ternary(n, i)
            if "1" in ternary:
                sys.stdout.write(" ")
            else:
                sys.stdout.write("-")
        sys.stdout.write("\n")


main()
