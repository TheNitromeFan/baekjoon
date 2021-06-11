import sys
import collections


def members(adj, groups, start):
    names = set()
    q = collections.deque()
    visited = set()
    q.append(start)
    visited.add(start)
    while q:
        u = q.popleft()
        if u in groups:
            for v in adj[u]:
                if v not in visited:
                    q.append(v)
                    visited.add(v)
        else:
            names.add(u)
    return len(names)


def main():
    while True:
        n = int(sys.stdin.readline())
        if n == 0:
            break
        groups = set()
        adj = {}
        for _ in range(n):
            line = sys.stdin.readline().rstrip()
            group, names = line[:-1].split(":")
            if not groups:
                start = group
            groups.add(group)
            adj[group] = []
            for name in names.split(","):
                adj[group].append(name)
        print(members(adj, groups, start))


main()
