import string


alphabet = string.digits + string.ascii_uppercase + string.ascii_lowercase


def convert_base(p, q, n):
    if n == 0:
        return "0"
    ret = ""
    while n:
        ret += alphabet[n % p]
        n = n // p * q
    return ret[::-1]


def main():
    p, q, n = (int(x) for x in input().split())
    print(convert_base(p, q, n))


main()
