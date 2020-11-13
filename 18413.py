input()
a = [int(x) for x in input().split()]
print(max(a.count(x) for x in a))
