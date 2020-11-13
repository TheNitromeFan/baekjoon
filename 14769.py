import sys


def is_int(s):
    try:
        int(s)
        return True
    except ValueError:
        return False


def main():
    n = int(sys.stdin.readline())
    cups = {}
    for _ in range(n):
        x, y = sys.stdin.readline().rstrip().split()
        if is_int(x):
            cups[y] = int(x) // 2
        else:
            cups[x] = int(y)
    print("\n".join(sorted(cups.keys(), key=lambda x: cups[x])))


main()
