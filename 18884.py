import sys


def main():
    n, m = (int(x) for x in sys.stdin.readline().split())
    s = sys.stdin.readline().rstrip().split()
    t = sys.stdin.readline().rstrip().split()
    q = int(sys.stdin.readline())
    for _ in range(q):
        y = int(sys.stdin.readline())
        y -= 1
        print(s[y % n] + t[y % m])


main()
