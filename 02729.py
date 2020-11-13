t = int(input())
for _ in range(t):
    a, b = (int(x, base=2) for x in input().split())
    print(bin(a + b)[2:])
