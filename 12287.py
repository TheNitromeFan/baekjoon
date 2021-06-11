import sys


def dfs(adj, visited, u, color):
    visited[u] = color
    for v in adj[u]:
        if visited[v] == visited[u]:
            return False
        if not visited[v] and not dfs(adj, visited, v, 3 - color):
            return False
    return True


def two_color(adj):
    visited = {x: 0 for x in adj}
    for u in visited:
        if not visited[u] and not dfs(adj, visited, u, 1):
            return False
    return True


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        m = int(sys.stdin.readline())
        adj = {}
        for _ in range(m):
            u, v = sys.stdin.readline().rstrip().split()
            if u not in adj:
                adj[u] = []
            adj[u].append(v)
            if v not in adj:
                adj[v] = []
            adj[v].append(u)
        if two_color(adj):
            print(f"Case #{a0}: Yes")
        else:
            print(f"Case #{a0}: No")


main()
