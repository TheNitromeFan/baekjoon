import sys
import string


def is_prime(n):
    if n <= 1:
        return False
    for p in range(2, int(n ** 0.5) + 1):
        if n % p == 0:
            return False
    return True


def main():
    try:
        lines = "".join(sys.stdin.readlines())
        for c in lines:
            if c not in string.digits and not c.isspace():
                print(0)
                return
        a, b, c = lines.split()
        if '0' in [a[0], b[0], c[0]]:
            print(0)
            return
        a, b, c = int(a), int(b), int(c)
    except ValueError:
        print(0)
        return
    print(int(3 < a <= 10 ** 9 and a % 2 == 0 and is_prime(b) and is_prime(c) and a == b + c))


main()
