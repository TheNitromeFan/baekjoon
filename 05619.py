import sys
import itertools


def main():
    n = int(sys.stdin.readline())
    a, b = [], []
    min_length = 5
    for _ in range(n):
        x = sys.stdin.readline().rstrip()
        a.append(len(x))
        b.append(int(x))
    c = []
    for i, j in itertools.permutations(range(n), 2):
        c.append(b[i] * 10 ** a[j] + b[j])
        if len(c) > 3:
            c.remove(max(c))
    print(max(c))


main()