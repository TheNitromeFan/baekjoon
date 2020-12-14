import sys
import collections


def search(adj, start):
    ret = []
    dq = collections.deque()
    visited = {vertex: False for vertex in adj}
    dq.append(start)
    visited[start] = True
    while dq:
        u = dq.popleft()
        for v in adj[u]:
            if not visited[v]:
                ret.append(v)
                dq.append(v)
                visited[v] = True
    return sorted(ret)


def main():
    n = int(sys.stdin.readline())
    vertices = {"Baba"}
    adj = {"Baba": []}
    for _ in range(n):
        words = sys.stdin.readline().rstrip().split()
        p, q = words[0], words[2]
        if p in vertices:
            adj[p].append(q)
        else:
            vertices.add(p)
            adj[p] = [q]
        if q not in vertices:
            vertices.add(q)
            adj[q] = []
    sys.stdout.write("\n".join(search(adj, "Baba")))


main()
