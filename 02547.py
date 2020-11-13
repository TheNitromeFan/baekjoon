import sys


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        sys.stdin.readline()
        n = int(sys.stdin.readline())
        s = 0
        for _ in range(n):
            s += int(sys.stdin.readline())
        if s % n == 0:
            print("YES")
        else:
            print("NO")


main()
