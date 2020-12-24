import sys
import collections


def main():
    s1 = sys.stdin.readline().rstrip()
    s2 = sys.stdin.readline().rstrip()
    c1, c2 = collections.Counter(s1), collections.Counter(s2)
    if sorted(c1.values()) == sorted(c2.values()):
        sys.stdout.write("YES")
    else:
        sys.stdout.write("NO")


main()
