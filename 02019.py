import sys
import collections


def polygon(adj, visited, point):
    dq = collections.deque()
    dq.append(point)
    visited[point] = True
    component = {point}
    while dq:
        u = dq.popleft()
        for v in adj[u]:
            if v not in component:
                dq.append(v)
                visited[v] = True
                component.add(v)
    return len(component) >= 3 and all(len(adj[v]) == 2 for v in component)


def main():
    n = int(sys.stdin.readline())
    points = set()
    adj = {}
    for _ in range(n):
        x1, y1, x2, y2 = (int(z) for z in sys.stdin.readline().split())
        if (x1, y1) in points:
            adj[(x1, y1)].append((x2, y2))
        else:
            points.add((x1, y1))
            adj[(x1, y1)] = [(x2, y2)]
        if (x2, y2) in points:
            adj[(x2, y2)].append((x1, y1))
        else:
            points.add((x2, y2))
            adj[(x2, y2)] = [(x1, y1)]
    visited = {point: False for point in points}
    ans = 0
    for point in points:
        if not visited[point] and polygon(adj, visited, point):
            ans += 1
    print(ans)


main()
