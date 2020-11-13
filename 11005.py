import string


symbols = string.digits + string.ascii_uppercase


def convert(number, base):
    ret = ""
    while number:
        ret = symbols[number % base] + ret
        number //= base
    return ret


def main():
    n, b = (int(x) for x in input().split())
    print(convert(n, b))


main()
