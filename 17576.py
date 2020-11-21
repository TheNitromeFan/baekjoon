import sys


def main():
    s = sys.stdin.readline().rstrip()
    n = int(sys.stdin.readline().rstrip())
    i = 0
    for _ in range(n):
        start, length = (int(x) for x in sys.stdin.readline().split())
        i += start
    sys.stdout.write(s[i:i + length])


main()
