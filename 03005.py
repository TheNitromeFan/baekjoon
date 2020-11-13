r, c = (int(x) for x in input().split())
board = {}
for i in range(r):
    line = input()
    for j in range(c):
        board[(i, j)] = line[j]
board1 = ["".join(board[(i, j)] for j in range(c)) for i in range(r)]
board2 = ["".join(board[(i, j)] for i in range(r)) for j in range(c)]
ans = 'z' * 21
for line in board1 + board2:
    for word in line.split("#"):
        if len(word) >= 2 and word < ans:
            ans = word
print(ans)
