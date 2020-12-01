import sys
import itertools


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        entries = [int(x) for x in sys.stdin.readline().split()]
        n, players = entries[0], entries[1:]
        sys.stdout.write("Case #{}: {}\n".format(a0, min(abs(2 * sum(team) - sum(players)) for team in
                                                         itertools.combinations(players, n // 2))))


main()
