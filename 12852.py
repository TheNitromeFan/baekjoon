def operations(number):
    counts = [None] * (number+1)
    counts[1] = [0, [1]]
    for i in range(2, number+1):
        counts[i] = [counts[i-1][0] + 1, [i] + counts[i-1][1]]
        if i % 2 == 0 and counts[i//2][0] + 1 < counts[i][0]:
            counts[i][0] = counts[i//2][0] + 1
            counts[i][1] = [i] + counts[i//2][1]
        if i % 3 == 0 and counts[i // 3][0] + 1 < counts[i][0]:
            counts[i][0] = counts[i // 3][0] + 1
            counts[i][1] = [i] + counts[i // 3][1]
    return counts[number]


cnt, seq = operations(int(input()))
print(cnt)
print(" ".join(str(x) for x in seq))
