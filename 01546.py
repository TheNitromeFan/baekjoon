n = int(input())
scores = [int(x) for x in input().split()]
print("{0:.2f}".format(sum(scores) / max(scores) * 100 / n))
