n = int(input())
codes = [int(x) for x in input().split()]
counts = {x: codes.count(x) for x in [0, 1, 2, 4, 8, 16]}
length = counts[0] * 2 + sum(counts[x] / x for x in [1, 2, 4, 8, 16])
print(length)
