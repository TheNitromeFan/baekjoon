import sys


def main():
    n, d = (int(x) for x in sys.stdin.readline().split())
    if d >= 10 ** n:
        print("No solution")
        return
    while d < 10 ** (n - 1):
        d *= 10
    print(d)


main()
