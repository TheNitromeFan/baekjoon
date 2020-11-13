import sys


def main():
    n = int(sys.stdin.readline())
    s = []
    for _ in range(n):
        s.append(sys.stdin.readline().rstrip())
    q = int(sys.stdin.readline())
    for _ in range(q):
        w = sys.stdin.readline().rstrip()
        if any(word in w for word in s):
            print("YES")
        else:
            print("NO")


main()
