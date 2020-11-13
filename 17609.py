import sys


def palindrome(s):
    if s == s[::-1]:
        return 0
    for idx, _ in enumerate(s):
        t = s[:idx] + s[idx + 1:]
        if t == t[::-1]:
            return 1
    return 2


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        word = sys.stdin.readline().rstrip()
        print(palindrome(word))


main()
