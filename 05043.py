n, b = (int(x) for x in input().split())
if n <= 2 ** (b + 1) - 1:
    print("yes")
else:
    print("no")
