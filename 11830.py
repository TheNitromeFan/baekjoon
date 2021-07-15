import sys


n = int(sys.stdin.readline())
a = {}
b = {}
points = []
for _ in range(n):
    x, y = (int(z) for z in sys.stdin.readline().split())
    if x not in a:
        a[x] = 0
    a[x] += 1
    if y not in b:
        b[y] = 0
    b[y] += 1
    points.append((x, y))
ans = 0
for x, y in points:
    ans += (a[x] - 1) * (b[y] - 1)
print(ans)
