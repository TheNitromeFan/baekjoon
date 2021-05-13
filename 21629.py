import sys


def paths(adj, visited, dest, cur, steps):
    if steps == 3:
        return int(cur in dest)
    ret = 0
    visited[cur] = True
    for v in adj[cur]:
        if visited[v]:
            continue
        ret += paths(adj, visited, dest, v, steps + 1)
    visited[cur] = False
    return ret


def main():
    n, m = (int(x) for x in sys.stdin.readline().split())
    adj = [[] for _ in range(n + 1)]
    dest = set()
    for _ in range(m):
        u, v = (int(x) for x in sys.stdin.readline().split())
        adj[u].append(v)
        adj[v].append(u)
        if u == 1:
            dest.add(v)
        if v == 1:
            dest.add(u)
    visited = [False for _ in range(n + 1)]
    print(paths(adj, visited, dest, 1, 0))


main()
