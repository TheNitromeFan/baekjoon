import sys


def main():
    n = int(sys.stdin.readline())
    translator = {}
    for _ in range(n):
        x, y = sys.stdin.readline().rstrip().split(" = ")
        translator[x] = y
    t = int(sys.stdin.readline())
    for _ in range(t):
        sys.stdin.readline()
        words = sys.stdin.readline().rstrip().split()
        print(" ".join(translator[word] for word in words))


main()
