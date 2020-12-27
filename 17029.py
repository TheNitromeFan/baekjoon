import sys
import itertools


def main():
    n = int(sys.stdin.readline())
    animals = {}
    for _ in range(n):
        entries = sys.stdin.readline().rstrip().split()
        animals[entries[0]] = set(entries[2:])
    ans = 0
    for a1, a2 in itertools.combinations(animals, 2):
        ans = max(ans, len(animals[a1] & animals[a2]) + 1)
    print(ans)


main()
