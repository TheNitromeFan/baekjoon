import sys


def main():
    n = int(sys.stdin.readline())
    votes = {}
    for _ in range(n):
        name = sys.stdin.readline().rstrip()
        if name in votes:
            votes[name] += 1
        else:
            votes[name] = 1
    winners = [name for name in votes if votes[name] == max(votes.values())]
    sys.stdout.write("\n".join(sorted(winners)))


main()
