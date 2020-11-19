import sys


def main():
    m, n = (int(y) for y in sys.stdin.readline().split())
    universes = []
    for _ in range(m):
        x = [int(y) for y in sys.stdin.readline().split()]
        a = list(set(x))
        a.sort()
        d = {val: ind for ind, val in enumerate(a)}
        compressed = [d[xi] for xi in x]
        universes.append(compressed)
    universes.sort()
    same_count = 0
    pairs = 0
    for i in range(m - 1):
        if universes[i] == universes[i + 1]:
            same_count += 1
        else:
            pairs += same_count * (same_count + 1) // 2
            same_count = 0
    pairs += same_count * (same_count + 1) // 2
    sys.stdout.write(str(pairs))


main()
