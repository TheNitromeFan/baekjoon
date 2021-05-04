import sys


def main():
    n = int(sys.stdin.readline())
    a = [int(x) for x in sys.stdin.readline().rstrip().split()]
    swaps = []
    for i in range(1, n + 1):
        j = a.index(i) + 1
        if j != i:
            a = a[:i - 1] + a[i - 1:j][::-1] + a[j:]
            swaps.append((i, j))
    print(len(swaps))
    for i, j in swaps:
        print(i, j)


main()
