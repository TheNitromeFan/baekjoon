import sys


def divide(a, k):
    while len(a) > k:
        a[-k-1] -= a[-1]
        a.pop()
    while len(a) > 1 and a[-1] == 0:
        a.pop()


def main():
    while True:
        n, k = (int(x) for x in sys.stdin.readline().split())
        if n == k == -1:
            break
        a = [int(x) for x in sys.stdin.readline().split()]
        if k > 0:
            divide(a, k)
        else:
            a = [0]
        sys.stdout.write(" ".join(str(x) for x in a) + "\n")


main()
