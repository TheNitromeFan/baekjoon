import sys


def main():
    s = sys.stdin.readline().rstrip()
    n = len(s)
    words = [s[:n//3], s[n//3:-n//3], s[-n//3:]]
    print(max(words, key=lambda x: words.count(x)))


main()
