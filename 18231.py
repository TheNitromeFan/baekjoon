import sys


def main():
    n, m = (int(x) for x in sys.stdin.readline().split())
    adj = [[] for _ in range(n + 1)]
    for _ in range(m):
        u, v = (int(x) for x in sys.stdin.readline().split())
        adj[u].append(v)
        adj[v].append(u)
    sys.stdin.readline()
    fire = [int(x) for x in sys.stdin.readline().split()]
    fire_set = set(fire)
    running_vertices = []
    running_union = set()
    for u in fire:
        if all(v in fire_set for v in adj[u]):
            running_vertices.append(u)
            running_union.add(u)
            running_union |= set(adj[u])
    if running_union == fire_set:
        print(f"{len(running_vertices)}\n{' '.join(str(x) for x in running_vertices)}")
    else:
        print(-1)


main()
