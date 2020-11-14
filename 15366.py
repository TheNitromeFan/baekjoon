import sys


def main():
    n = int(sys.stdin.readline())
    x = sorted(int(x) for x in sys.stdin.readline().split())
    y = sorted(int(x) for x in sys.stdin.readline().split())
    if all(x[i] <= y[i] for i in range(n)):
        print("DA")
    else:
        print("NE")


main()
