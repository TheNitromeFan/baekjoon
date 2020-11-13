import sys


def main():
    while True:
        d, n = sys.stdin.readline().rstrip().split()
        if d == n == "0":
            break
        number = "".join(x for x in n if x != d)
        if not number:
            number = "0"
        print(int(number))


main()
