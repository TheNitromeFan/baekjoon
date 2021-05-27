import sys


while True:
    n, m = (int(x) for x in sys.stdin.readline().split())
    if n == m == 0:
        break
    candidates = []
    for _ in range(n):
        candidates.append(sys.stdin.readline().rstrip())
    candidates.append(None)
    supporters = []
    votes = {}
    for _ in range(m):
        supporter, vote = sys.stdin.readline().rstrip().split()
        supporters.append(supporter)
        if vote not in candidates:
            candidates.append(vote)
        votes[supporter] = vote
    supporters.sort(key=lambda x: candidates.index(votes[x]))
    for supporter in supporters:
        print(supporter)
