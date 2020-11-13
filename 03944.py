t = int(input())
for _ in range(t):
    x = input().split()
    b = int(x[0])
    d = sum(int(y) for y in x[1])
    print(d % (b - 1))
