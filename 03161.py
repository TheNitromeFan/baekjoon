import sys


m, n = (int(x) for x in sys.stdin.readline().split())
votes = []
for _ in range(m):
    vote = [int(x) for x in sys.stdin.readline().split()]
    votes.append(vote)
scores = {x: 0 for x in range(1, n + 1)}
for a in range(1, n + 1):
    for b in range(1, a):
        a_count, b_count = 0, 0
        for vote in votes:
            if vote.index(a) < vote.index(b):
                a_count += 1
            else:
                b_count += 1
        if a_count > b_count:
            scores[a] += 1
        else:
            scores[b] += 1
list1 = sorted(scores.items(), key=lambda x: (-x[1], x[0]))
ans = []
idx = 0
while idx < n and list1[idx][1] == list1[0][1]:
    ans.append(list1[idx][0])
    idx += 1
sys.stdout.write("\n".join(str(x) for x in ans))
