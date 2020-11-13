n = int(input())
board = []
for _ in range(n):
    board.append([int(x) for x in input().split()])
ways = [[0 for _ in range(n)] for _ in range(n)]
ways[0][0] = 1
for i in range(n):
    for j in range(n):
        if board[i][j] == 0:
            continue
        if i + board[i][j] < n:
            ways[i + board[i][j]][j] += ways[i][j]
        if j + board[i][j] < n:
            ways[i][j + board[i][j]] += ways[i][j]
print(ways[n - 1][n - 1])
