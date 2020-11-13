import sys


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        sys.stdin.readline()
        a = {int(x) for x in sys.stdin.readline().split()}
        b = {int(x) for x in sys.stdin.readline().split()}
        if 2 * len(a & b) > len(a | b):
            print(1)
        else:
            print(0)


main()
