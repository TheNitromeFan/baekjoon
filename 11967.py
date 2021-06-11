import sys
import collections


def bfs(adj, n):
    q = collections.deque()
    lit = {p: False for p in adj}
    visited = {p: False for p in adj}
    can_move = {p: False for p in adj}
    q.append((1, 1))
    visited[(1, 1)] = True
    lit[(1, 1)] = True
    can_move[(1, 1)] = True
    ret = 1
    while q:
        x, y = q.popleft()
        for a, b in adj[(x, y)]:
            if not lit[(a, b)]:
                lit[(a, b)] = True
                ret += 1
            if not visited[(a, b)] and can_move[(a, b)]:
                q.append((a, b))
                visited[(a, b)] = True
        for dx, dy in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
            nx, ny = x + dx, y + dy
            if 1 <= nx <= n and 1 <= ny <= n:
                can_move[(nx, ny)] = True
                if not visited[(nx, ny)] and lit[(nx, ny)]:
                    q.append((nx, ny))
                    visited[(nx, ny)] = True
    return ret


def main():
    n, m = (int(x) for x in sys.stdin.readline().split())
    adj = {(x, y): [] for x in range(1, n + 1) for y in range(1, n + 1)}
    for _ in range(m):
        x, y, a, b = (int(z) for z in sys.stdin.readline().split())
        adj[(x, y)].append((a, b))
    print(bfs(adj, n))


main()
