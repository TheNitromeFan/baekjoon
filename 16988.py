import sys
import collections
import heapq


scanf = sys.stdin.readline
printf = sys.stdout.write


def adjacent_empty(board, visited, n, m, sx, sy):
    q = collections.deque()
    q.append((sx, sy))
    visited[(sx, sy)] = True
    ret = set()
    point_count = 0
    while q:
        x, y = q.popleft()
        point_count += 1
        for dx, dy in [(-1, 0), (0, 1), (1, 0), (0, -1)]:
            nx, ny = x + dx, y + dy
            if 0 <= nx < n and 0 <= ny < m and board[(nx, ny)] == 0:
                ret.add((nx, ny))
            elif 0 <= nx < n and 0 <= ny < m and board[(nx, ny)] == 2 and not visited[(nx, ny)]:
                q.append((nx, ny))
                visited[(nx, ny)] = True
    return ret, point_count


def main():
    n, m = (int(x) for x in scanf().split())
    board = {}
    for i in range(n):
        entries = [int(x) for x in scanf().split()]
        for j in range(m):
            board[(i, j)] = entries[j]
    visited = {p: False for p in board}
    candidates_one_point = {}
    candidates_two_points = {}
    for i in range(n):
        for j in range(m):
            if board[(i, j)] == 2 and not visited[(i, j)]:
                adjacent_points, point_count = adjacent_empty(board, visited, n, m, i, j)
                if len(adjacent_points) == 1:
                    p = adjacent_points.pop()
                    if p in candidates_one_point:
                        candidates_one_point[p] += point_count
                    else:
                        candidates_one_point[p] = point_count
                elif len(adjacent_points) == 2:
                    p1, p2 = tuple(adjacent_points)
                    if p1 > p2:
                        p1, p2 = p2, p1
                    if (p1, p2) in candidates_two_points:
                        candidates_two_points[(p1, p2)] += point_count
                    else:
                        candidates_two_points[(p1, p2)] = point_count
    # print(candidates_one_point)
    # print(candidates_two_points)
    ans = sum(heapq.nlargest(2, candidates_one_point.values()))
    for p1, p2 in candidates_two_points:
        cmp = candidates_two_points[(p1, p2)]
        if p1 in candidates_one_point:
            cmp += candidates_one_point[p1]
        if p2 in candidates_one_point:
            cmp += candidates_one_point[p2]
        ans = max(ans, cmp)
    print(ans)


main()
