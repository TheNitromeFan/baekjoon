import collections


def bfs(m, n, grid, start, value):
    queue = collections.deque([start])
    while queue:
        x, y = queue.popleft()
        if x+1 < m and (grid[(x+1, y)] == "0" or (grid[(x+1, y)] == "1" and value[(x+1, y)] > value[(x, y)] + 1)):
            grid[(x+1, y)] = "1"
            value[(x+1, y)] = value[(x, y)] + 1
            queue.append((x+1, y))
        if x-1 >= 0 and (grid[(x-1, y)] == "0" or (grid[(x-1, y)] == "1" and value[(x-1, y)] > value[(x, y)] + 1)):
            grid[(x-1, y)] = "1"
            value[(x-1, y)] = value[(x, y)] + 1
            queue.append((x-1, y))
        if y+1 < n and (grid[(x, y+1)] == "0" or (grid[(x, y+1)] == "1" and value[(x, y+1)] > value[(x, y)] + 1)):
            grid[(x, y+1)] = "1"
            value[(x, y+1)] = value[(x, y)] + 1
            queue.append((x, y+1))
        if y-1 >= 0 and (grid[(x, y-1)] == "0" or (grid[(x, y-1)] == "1" and value[(x, y-1)] > value[(x, y)] + 1)):
            grid[(x, y-1)] = "1"
            value[(x, y-1)] = value[(x, y)] + 1
            queue.append((x, y-1))


def max_days(m, n, grid, days):
    answer = 0
    for j in range(n):
        for i in range(m):
            if grid[(i, j)] == "0":
                return -1
            elif grid[(i, j)] != "-1" and days[(i, j)] > answer:
                answer = days[(i, j)]
    return answer


def main():
    m, n = (int(x) for x in input().split())
    grid = {}
    for j in range(n):
        for i, v in enumerate(input().split()):
            grid[(i, j)] = v
    ripe = []
    for key in grid:
        if grid[key] == "1":
            ripe.append(key)
    days = {(i, j): 0 for i in range(m) for j in range(n)}
    for tomato in ripe:
        bfs(m, n, grid, tomato, days)
    print(max_days(m, n, grid, days))


main()
