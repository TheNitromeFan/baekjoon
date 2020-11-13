def operations(number):
    counts = [0] * (number+1)
    for i in range(2, number+1):
        counts[i] = counts[i-1] + 1
        if i % 2 == 0:
            counts[i] = min(counts[i], counts[i//2] + 1)
        if i % 3 == 0:
            counts[i] = min(counts[i], counts[i//3] + 1)
    return counts[number]


print(operations(int(input())))
