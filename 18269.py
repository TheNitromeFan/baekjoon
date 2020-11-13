import sys


def m(s, k):
    x = set()
    for i in range(len(s) - k + 1):
        if s[i:i + k] in x:
            return False
        x.add(s[i:i + k])
    return True


def main():
    n = int(sys.stdin.readline())
    mailboxes = sys.stdin.readline().rstrip()
    for k in range(1, n + 1):
        if m(mailboxes, k):
            print(k)
            break


main()
