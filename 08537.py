import sys


def main():
    n = int(sys.stdin.readline())
    words = []
    for _ in range(n):
        words.append(sys.stdin.readline().rstrip())
    print(max(len(set(word)) for word in words))


main()
