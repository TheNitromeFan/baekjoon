import sys


def roll(board, dp, x, y):
    if (x, y) in dp:
        return dp[(x, y)]
    best = (x, y)
    for dx, dy in [(-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1)]:
        nx, ny = x + dx, y + dy
        if (nx, ny) in board and board[(nx, ny)] < board[best]:
            best = (nx, ny)
    if best == (x, y):
        dp[(x, y)] = (x, y)
        return x, y
    dp[(x, y)] = roll(board, dp, best[0], best[1])
    return dp[(x, y)]


def main():
    r, c = (int(x) for x in sys.stdin.readline().split())
    board = {}
    for i in range(r):
        entries = [int(x) for x in sys.stdin.readline().split()]
        for j in range(c):
            board[(i, j)] = entries[j]
    dp = {}
    counts = {(i, j): 0 for i in range(r) for j in range(c)}
    for i in range(r):
        for j in range(c):
            x, y = roll(board, dp, i, j)
            counts[(x, y)] += 1
    # print(dp)
    for i in range(r):
        for j in range(c):
            print(counts[(i, j)], end=" ")
        print()


main()
