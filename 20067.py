import sys
import random


def main0():
    n, m, k = (int(x) for x in sys.stdin.readline().split())
    mark = [[False for _ in range(m)] for _ in range(n)]
    free = [(x, y) for x in range(n) for y in range(m)]
    dxdy = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    mark[0][0] = True
    while True:
        changed = False
        for x in range(n):
            for y in range(m):
                if mark[x][y]:
                    continue
                free_count = 0
                for dx, dy in dxdy:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < n and 0 <= ny < m and mark[nx][ny]:
                        free_count += 1
                if free_count == 1:
                    if not mark[x][y]:
                        changed = True
                    mark[x][y] = True
        if not changed:
            break
    ans = []
    for x in range(n):
        line = ""
        for y in range(m):
            if mark[x][y]:
                line += '.'
            else:
                line += 'X'
        ans.append(line)
    cmp = 0
    for x in range(n):
        for y in range(m):
            if not mark[x][y]:
                continue
            adj_count = 0
            for dx, dy in dxdy:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < m and mark[nx][ny]:
                    adj_count += 1
            if adj_count == 1:
                cmp += 1
    print(cmp)
    for line in ans:
        sys.stdout.write(line + "\n")


def main():
    n, m, k = (int(x) for x in sys.stdin.readline().split())
    grid = []
    for _ in range(n):
        grid.append(sys.stdin.readline().rstrip())
    dxdy = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    ans = []
    cnt = 0
    while cnt < k:
        mark = [[False for _ in range(m)] for _ in range(n)]
        free = []
        for i in range(n):
            for j in range(m):
                if grid[i][j] == '.':
                    free.append((i, j))
        random.shuffle(free)
        x, y = free[0]
        mark[x][y] = True
        while True:
            random.shuffle(free)
            changed = False
            for x, y in free:
                free_count = 0
                for dx, dy in dxdy:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < n and 0 <= ny < m and mark[nx][ny]:
                        free_count += 1
                if free_count == 1:
                    if not mark[x][y]:
                        changed = True
                    mark[x][y] = True
            if not changed:
                break
        cmp = 0
        for x in range(n):
            for y in range(m):
                if not mark[x][y]:
                    continue
                adj_count = 0
                for dx, dy in dxdy:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < n and 0 <= ny < m and mark[nx][ny]:
                        adj_count += 1
                if adj_count == 1:
                    cmp += 1
        if cmp > cnt:
            cnt = cmp
            ans = []
            for x in range(n):
                line = ""
                for y in range(m):
                    if grid[x][y] == '#':
                        line += '#'
                    elif mark[x][y]:
                        line += '.'
                    else:
                        line += 'X'
                ans.append(line)
        print(cnt)
    print(cnt)
    for line in ans:
        sys.stdout.write(line + "\n")


main()
