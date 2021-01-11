import sys
import itertools


def good(spotty, plain, x, y, z):
    acgt = set()
    for cow in spotty:
        acgt.add(cow[x] + cow[y] + cow[z])
    for cow in plain:
        if cow[x] + cow[y] + cow[z] in acgt:
            return False
    return True


def main():
    n, m = (int(x) for x in sys.stdin.readline().split())
    spotty = []
    for _ in range(n):
        spotty.append(sys.stdin.readline().rstrip())
    plain = []
    for _ in range(n):
        plain.append(sys.stdin.readline().rstrip())
    ans = 0
    for x, y, z in itertools.combinations(range(m), 3):
        if good(spotty, plain, x, y, z):
            ans += 1
    print(ans)


main()
