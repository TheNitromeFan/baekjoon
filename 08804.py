import sys


def main():
    z = int(sys.stdin.readline())
    for _ in range(z):
        s = sys.stdin.readline().rstrip()
        if s == s[::-1]:
            print(1)
        else:
            print(2)


main()
