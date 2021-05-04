import sys


def main():
    n, m = (int(x) for x in sys.stdin.readline().split())
    teams = [f"T{x}" for x in range(1, n + 1)]
    for _ in range(m):
        team1, team2 = sys.stdin.readline().rstrip().split()
        rank1, rank2 = teams.index(team1), teams.index(team2)
        if rank1 > rank2:
            teams.insert(rank1 + 1, team2)
            teams.pop(rank2)
    sys.stdout.write(" ".join(teams))


main()
