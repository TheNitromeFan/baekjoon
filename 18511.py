import sys
import itertools


def largest(n, k):
    candidates = []
    for length in range(len(str(n)), 0, -1):
        for candidate in itertools.product(k, repeat=length):
            number = "".join(candidate)
            if int(number) <= n:
                candidates.append(number)
            else:
                break
        if candidates:
            return candidates[-1]


def main():
    n = int(sys.stdin.readline().split()[0])
    k = sys.stdin.readline().rstrip().split()
    k.sort()
    print(largest(n, k))


main()
