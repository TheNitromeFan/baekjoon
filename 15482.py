x = input()
y = input()
lcs = {}
for i in range(len(x) + 1):
    for j in range(len(y) + 1):
        if i == 0 or j == 0:
            lcs[(i, j)] = 0
        elif x[i - 1] == y[j - 1]:
            lcs[(i, j)] = lcs[(i - 1, j - 1)] + 1
        else:
            lcs[(i, j)] = max(lcs[(i - 1, j)], lcs[(i, j - 1)])
print(lcs[(len(x), len(y))])
