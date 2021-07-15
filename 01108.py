import sys
import collections


def traverse(adj, visited, post_order, u):
    if visited[u]:
        return
    visited[u] = True
    for v in adj[u]:
        traverse(adj, visited, post_order, v)
    post_order.append(u)


def assign_scc(rev, assigned, v, scc):
    if assigned[v] is not None:
        return
    assigned[v] = scc
    for u in rev[v]:
        assign_scc(rev, assigned, u, scc)


def main():
    n = int(sys.stdin.readline())
    adj, rev = {}, {}
    for _ in range(n):
        entries = sys.stdin.readline().rstrip().split()
        v = entries[0]
        if v not in adj:
            adj[v] = []
            rev[v] = []
        for u in entries[2:]:
            if u not in adj:
                adj[u] = []
                rev[u] = []
            adj[u].append(v)
            rev[v].append(u)
    visited = {x: False for x in adj}
    post_order = []
    for u in adj:
        traverse(adj, visited, post_order, u)
    post_order.reverse()
    scc = {x: None for x in adj}
    for v in post_order:
        assign_scc(rev, scc, v, v)
    for u in adj:
        new_list = []
        for v in adj[u]:
            if scc[u] != scc[v]:
                new_list.append(v)
        adj[u] = new_list
    indegree = {x: 0 for x in adj}
    for u in adj:
        for v in adj[u]:
            indegree[v] += 1
    scores = {x: 1 for x in adj}
    q = collections.deque()
    for u in indegree:
        if indegree[u] == 0:
            q.append(u)
    while q:
        u = q.popleft()
        for v in adj[u]:
            scores[v] += scores[u]
            indegree[v] -= 1
            if indegree[v] == 0:
                q.append(v)
    x = sys.stdin.readline().rstrip()
    sys.stdout.write(f"{scores[x]}\n")


main()
