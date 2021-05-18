import sys
import collections


def bfs(adj, start):
    dist = {v: -1 for v in adj}
    q = collections.deque()
    dist[start] = 0
    q.append(start)
    ans = []
    while q:
        u = q.popleft()
        if dist[u] == 2:
            ans.append(u)
        elif dist[u] > 2:
            break
        for v in adj[u]:
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.append(v)
    print(" ".join(sorted(ans)))


def main():
    sys.stdin.readline()
    while True:
        adj = {}
        while True:
            try:
                line = sys.stdin.readline().rstrip()
            except (ValueError, EOFError):
                return
            if line == "":
                return
            elif line == "GRAPH END":
                break
            nodes = line.split()
            u = nodes[0]
            if u not in adj:
                adj[u] = []
            for v in nodes[1:]:
                if v not in adj:
                    adj[v] = []
                adj[u].append(v)
                adj[v].append(u)
        while True:
            try:
                node = sys.stdin.readline().rstrip()
            except (ValueError, EOFError):
                return
            if node in ["", "GRAPH BEGIN"]:
                break
            bfs(adj, node)


main()
