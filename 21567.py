import sys


def main():
    a = int(sys.stdin.readline())
    b = int(sys.stdin.readline())
    c = int(sys.stdin.readline())
    prod = a * b * c
    digits = [0] * 10
    while prod:
        digits[prod % 10] += 1
        prod //= 10
    for digit in digits:
        sys.stdout.write(f"{digit}\n")


main()
