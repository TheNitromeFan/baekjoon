import sys
sys.setrecursionlimit(30000)


def knuth(a, b):
    if b == 1:
        return a
    else:
        return a ** knuth(a, b-1)


def main():
    a, b = (int(x) for x in input().split())
    print(knuth(a, b) % (10 ** 8))


main()
