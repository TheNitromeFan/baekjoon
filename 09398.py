import sys
import string


def good_password(pw):
    return len(pw) >= 6 and any(x in string.ascii_uppercase for x in pw) \
           and any(x in string.ascii_lowercase for x in pw) and any(x in string.digits for x in pw)


def shortest_password(s):
    for length in range(6, len(s) + 1):
        for i in range(0, len(s) - length + 1):
            if good_password(s[i: i + length]):
                return length
    return 0


def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        s = sys.stdin.readline().rstrip()
        print(shortest_password(s))


main()
