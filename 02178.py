import collections


def bfs(n, m, grid, start, value):
    queue = collections.deque([start])
    visited = {key: False for key in grid}
    while queue:
        x, y = queue.popleft()
        visited[(x, y)] = True
        if x+1 < m and grid[(x+1, y)] == "1" and not visited[(x+1, y)]:
            value[(x+1, y)] = value[(x, y)] + 1
            queue.append((x+1, y))
        if x-1 >= 0 and grid[(x-1, y)] == "1" and not visited[(x-1, y)]:
            value[(x-1, y)] = value[(x, y)] + 1
            queue.append((x-1, y))
        if y+1 < n and grid[(x, y+1)] == "1" and not visited[(x, y+1)]:
            value[(x, y+1)] = value[(x, y)] + 1
            queue.append((x, y+1))
        if y-1 >= 0 and grid[(x, y-1)] == "1" and not visited[(x, y-1)]:
            value[(x, y-1)] = value[(x, y)] + 1
            queue.append((x, y-1))
    return value[(m-1, n-1)]


def main():
    n, m = (int(x) for x in input().split())
    grid = {}
    for j in range(n):
        for i, v in enumerate(input()):
            grid[(i, j)] = v
    steps = {(i, j): 1 for i in range(m) for j in range(n)}
    print(bfs(n, m, grid, (0, 0), steps))


main()
