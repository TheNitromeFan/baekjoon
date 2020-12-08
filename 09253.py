import sys


def main():
    s = sys.stdin.readline().rstrip()
    t = sys.stdin.readline().rstrip()
    ans = sys.stdin.readline().rstrip()
    if ans in s and ans in t:
        sys.stdout.write("YES")
    else:
        sys.stdout.write("NO")


main()
