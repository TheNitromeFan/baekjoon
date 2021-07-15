import sys
import collections


def bfs(adj, n, start, end):
    dist = [-1 for _ in range(n)]
    q = collections.deque()
    dist[start] = 0
    q.append(start)
    while q:
        u = q.popleft()
        if u == end:
            return dist[u]
        for v in adj[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)


def main():
    c = int(sys.stdin.readline())
    countries = [None for _ in range(c)]
    for i in range(c):
        xyz = [int(w) for w in sys.stdin.readline().split()][1:]
        vertices = [tuple(xyz[i:i+3]) for i in range(0, len(xyz), 3)]
        edges = {(vertices[j], vertices[j + 1]) for j in range(-1, len(vertices) - 1)} \
                | {(vertices[j + 1], vertices[j]) for j in range(-1, len(vertices) - 1)}
        countries[i] = edges
    adj = [[] for _ in range(c)]
    for i in range(c):
        for j in range(i):
            if countries[i] & countries[j]:
                adj[i].append(j)
                adj[j].append(i)
    m = int(sys.stdin.readline())
    for _ in range(m):
        u, v = (int(w) for w in sys.stdin.readline().split())
        print(bfs(adj, c, u - 1, v - 1))


main()
