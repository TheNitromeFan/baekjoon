import sys


def main():
    lengths = [len(line.rstrip()) for line in sys.stdin.readlines()]
    n = max(lengths)
    print(sum((n - m) * (n - m) for m in lengths[:-1]))


main()
