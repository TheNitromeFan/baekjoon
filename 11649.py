import sys


def main():
    n = int(sys.stdin.readline())
    words = []
    for _ in range(n):
        words.append(sys.stdin.readline().rstrip())
    sys.stdout.write("\n".join(sorted(word[::-1] for word in words)))


main()
