import sys
import collections


def bfs(adj, start, end):
    visited = {name: False for name in adj}
    q = collections.deque()
    for name in start:
        visited[name] = True
        q.append(name)
    while q:
        name = q.popleft()
        for name1 in adj[name]:
            if not visited[name1]:
                visited[name1] = True
                q.append(name1)
    return [name for name in end if visited[name]]


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        u, v, m = (int(x) for x in sys.stdin.readline().split())
        start = sys.stdin.readline().rstrip().split()
        end = sys.stdin.readline().rstrip().split()
        adj = {}
        for name in start:
            if name not in adj:
                adj[name] = []
        for name in end:
            if name not in adj:
                adj[name] = []
        for _ in range(m):
            a, b = sys.stdin.readline().rstrip().split()
            if a in adj:
                adj[a].append(b)
            else:
                adj[a] = [b]
            if b not in adj:
                adj[b] = []
        ans = bfs(adj, start, end)
        print(" ".join(sorted(ans)))


main()
