import sys
import itertools


def main():
    n = int(sys.stdin.readline())
    k = int(sys.stdin.readline())
    a = []
    s = set()
    for _ in range(n):
        a.append(int(sys.stdin.readline()))
    for numbers in itertools.permutations(a, k):
        s.add("".join(str(x) for x in numbers))
    print(len(s))


main()
