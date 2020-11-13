import sys


def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        words = sys.stdin.readline().rstrip().split()
        print(" ".join(word if len(word) != 4 else "****" for word in words))
        print()


main()
