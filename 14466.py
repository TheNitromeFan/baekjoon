import sys
import collections


def cows_in_component(roads, cows, visited, n, sx, sy):
    q = collections.deque()
    q.append((sx, sy))
    visited[(sx, sy)] = True
    ret = 0
    while q:
        x, y = q.popleft()
        if (x, y) in cows:
            ret += 1
        # print(x, y)
        for dx, dy in [(-1, 0), (0, -1), (1, 0), (0, 1)]:
            nx, ny = x + dx, y + dy
            if 1 <= nx <= n and 1 <= ny <= n and (nx, ny) not in roads[(x, y)] and not visited[(nx, ny)]:
                q.append((nx, ny))
                visited[(nx, ny)] = True
    return ret


def main():
    n, k, r = (int(x) for x in sys.stdin.readline().split())
    roads = {(i, j): set() for i in range(1, n + 1) for j in range(1, n + 1)}
    for _ in range(r):
        x1, y1, x2, y2 = (int(z) for z in sys.stdin.readline().split())
        roads[(x1, y1)].add((x2, y2))
        roads[(x2, y2)].add((x1, y1))
    cows = set()
    for _ in range(k):
        x, y = (int(z) for z in sys.stdin.readline().split())
        cows.add((x, y))
    visited = {(i, j): False for i in range(1, n + 1) for j in range(1, n + 1)}
    c = []
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            if not visited[(i, j)]:
                c.append(cows_in_component(roads, cows, visited, n, i, j))
    # print(c)
    ans = 0
    for i in range(len(c)):
        for j in range(i):
            ans += c[i] * c[j]
    print(ans)


main()
