import sys
import itertools


def main():
    t = int(sys.stdin.readline())
    n = int(sys.stdin.readline())
    points = {x: 0 for x in range(1, 5)}
    matches = {(a, b): None for a, b in itertools.combinations(range(1, 5), 2)}
    for _ in range(n):
        a, b, sa, sb = (int(x) for x in sys.stdin.readline().split())
        if sa > sb:
            points[a] += 3
            matches[(a, b)] = 1
        elif sa < sb:
            points[b] += 3
            matches[(a, b)] = -1
        else:
            points[a] += 1
            points[b] += 1
            matches[(a, b)] = 0
    remaining = [pair for pair in matches if matches[pair] is None]
    ans = 0
    for prod in itertools.product((-1, 0, 1), repeat=len(remaining)):
        hypothetical = points.copy()
        for pair, result in zip(remaining, prod):
            if result == 1:
                hypothetical[pair[0]] += 3
            elif result == -1:
                hypothetical[pair[1]] += 3
            else:
                hypothetical[pair[0]] += 1
                hypothetical[pair[1]] += 1
        if all(hypothetical[t] > hypothetical[s] for s in {1, 2, 3, 4} - {t}):
            ans += 1
    print(ans)


main()
