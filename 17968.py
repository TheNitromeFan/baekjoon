import sys


def main():
    n = int(sys.stdin.readline())
    a = [1, 1]
    for i in range(2, n + 1):
        candidates = set(range(1, 10 ** 4))
        for k in range(1, i // 2 + 1):
            forbidden = 2 * a[i - k] - a[i - 2 * k]
            if forbidden in candidates:
                candidates.remove(forbidden)
        a.append(min(candidates))
    sys.stdout.write("{}".format(a[n]))


main()
