import sys
import collections


n = int(sys.stdin.readline())
names = sorted(sys.stdin.readline().rstrip().split())
adj = {x: [] for x in names}
indegree = {x: 0 for x in names}
m = int(sys.stdin.readline())
for _ in range(m):
    descendant, ancestor = sys.stdin.readline().rstrip().split()
    indegree[descendant] += 1
    adj[ancestor].append(descendant)
roots = []
q = collections.deque()
children = {x: [] for x in names}
for name in names:
    if indegree[name] == 0:
        roots.append(name)
        q.append(name)
while q:
    u = q.popleft()
    for v in adj[u]:
        indegree[v] -= 1
        if indegree[v] == 0:
            children[u].append(v)
            q.append(v)
print(len(roots))
print(" ".join(roots))
for name in names:
    print(name, len(children[name]), " ".join(sorted(children[name])))
