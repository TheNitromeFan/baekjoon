import sys
import collections


def traverse(adj, visited, post_order, u):
    if visited[u]:
        return
    visited[u] = True
    for v in adj[u]:
        traverse(adj, visited, post_order, v)
    post_order.append(u)


def assign_scc(rev, scc, v, val):
    if scc[v] is not None:
        return
    scc[v] = val
    for u in rev[v]:
        assign_scc(rev, scc, u, val)


def main():
    while True:
        n = int(sys.stdin.readline())
        if n == 0:
            break
        lines = []
        for _ in range(n):
            line = sys.stdin.readline().rstrip()
            lines.append(line)
        adj, rev = {}, {}
        edges = []
        for line in lines:
            entries = line.split()
            word = entries[0]
            if word not in adj:
                adj[word] = []
                rev[word] = []
            explain = set(entries[1:])
            for word1 in explain:
                if word1 not in adj:
                    adj[word1] = []
                    rev[word1] = []
                adj[word1].append(word)
                rev[word].append(word1)
                edges.append((word1, word))
        visited = {x: False for x in adj}
        post_order = []
        for u in adj:
            traverse(adj, visited, post_order, u)
        post_order.reverse()
        scc = {x: None for x in adj}
        for v in post_order:
            if scc[v] is None:
                assign_scc(rev, scc, v, v)
        scc_vertices = {}
        for u in adj:
            s = scc[u]
            if s not in scc_vertices:
                scc_vertices[s] = []
            scc_vertices[s].append(u)
        scc_rev = {}
        for u, v in edges:
            s, t = scc[u], scc[v]
            if s not in scc_rev:
                scc_rev[s] = []
            if t not in scc_rev:
                scc_rev[t] = []
            if s != t:
                scc_rev[t].append(s)
        q = collections.deque()
        scc_visited = {s: False for s in scc_vertices}
        for s in scc_vertices:
            if len(scc_vertices[s]) > 1:
                q.append(s)
                scc_visited[s] = True
        ans = []
        while q:
            s = q.popleft()
            for vertex in scc_vertices[s]:
                ans.append(vertex)
            for t in scc_rev[s]:
                if not scc_visited[t]:
                    q.append(t)
                    scc_visited[t] = True
        ans.sort()
        sys.stdout.write(f"{len(ans)}\n")
        for u in ans:
            sys.stdout.write(f"{u} ")


main()
