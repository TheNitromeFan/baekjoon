import sys


def main():
    while True:
        skew = sys.stdin.readline().rstrip()
        if skew == "0":
            break
        n = 0
        for i, val in enumerate(skew[::-1], start=1):
            n += int(val) * (2 ** i - 1)
        print(n)


main()
