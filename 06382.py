import sys
import collections


def bfs(adj, start, end):
    q = collections.deque()
    visited = {x: False for x in adj}
    q.append(start)
    visited[start] = True
    while q:
        u = q.popleft()
        if u == end:
            return True
        for v in adj[u]:
            if not visited[v]:
                q.append(v)
                visited[v] = True
    return False


def main():
    t = 0
    while True:
        n = int(sys.stdin.readline())
        if n == 0:
            break
        t += 1
        entries = [int(x) for x in sys.stdin.readline().split()]
        start, end = tuple(entries[:n]), tuple(entries[n:])
        adj = {start: [], end: []}
        while True:
            entries = [int(x) for x in sys.stdin.readline().split()]
            if entries == [-1]:
                break
            u, v = tuple(entries[:n]), tuple(entries[n:])
            if u not in adj:
                adj[u] = []
            adj[u].append(v)
            if v not in adj:
                adj[v] = []
            adj[v].append(u)
        if bfs(adj, start, end):
            print(f"Maze #{t} can be travelled")
        else:
            print(f"Maze #{t} cannot be travelled")


main()
