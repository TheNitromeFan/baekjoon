import sys
import itertools


def is_adjacent(cows, cow1, cow2):
    return abs(cows.index(cow1) - cows.index(cow2)) == 1


def formation(cows, adjacent):
    cows.sort()
    for arrangement in itertools.permutations(cows):
        if all(is_adjacent(arrangement, cow1, cow2) for cow1, cow2 in adjacent):
            return arrangement
    return cows


def main():
    cows = ["Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"]
    n = int(sys.stdin.readline())
    adjacent = []
    for _ in range(n):
        line = sys.stdin.readline().rstrip().split()
        cow1, cow2 = line[0], line[-1]
        adjacent.append((cow1, cow2))
    ans = formation(cows, adjacent)
    sys.stdout.write("\n".join(ans))


main()
