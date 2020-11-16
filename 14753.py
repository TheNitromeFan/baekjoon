import sys


def main():
    sys.stdin.readline()
    a = [int(x) for x in sys.stdin.readline().split()]
    a.sort()
    print(max(a[-1] * a[-2], a[0] * a[1], a[-1] * a[-2] * a[-3], a[-1] * a[0] * a[1]))


main()
