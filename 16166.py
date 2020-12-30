import sys
import collections


def transfers(adj, lines, n, start, end):
    dq = collections.deque()
    dist = [-1] * n
    for i in range(n):
        if start in lines[i]:
            dq.append(i)
            dist[i] = 0
    while dq:
        u = dq.popleft()
        if end in lines[u]:
            return dist[u]
        for v in adj[u]:
            if dist[v] == -1:
                dq.append(v)
                dist[v] = dist[u] + 1
    return -1


def main():
    n = int(sys.stdin.readline())
    lines = []
    for i in range(n):
        lines.append(set([int(x) for x in sys.stdin.readline().split()][1:]))
    start, end = 0, int(sys.stdin.readline())
    adj = {}
    for i in range(n):
        adj[i] = []
        for j in range(n):
            if j == i:
                continue
            if lines[i] & lines[j]:
                adj[i].append(j)
    print(transfers(adj, lines, n, start, end))


main()
