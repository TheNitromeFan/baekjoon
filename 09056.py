n = int(input())
for _ in range(n):
    a, b = input().split()
    if set(a) == set(b):
        print("YES")
    else:
        print("NO")
