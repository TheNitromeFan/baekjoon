import sys


scanf = sys.stdin.readline
printf = sys.stdout.write
n = int(scanf())
a, b = (int(x) for x in scanf().split())
points = set()
for _ in range(n):
    x, y = (int(z) for z in scanf().split())
    points.add((x, y))
cnt = 0
for x, y in points:
    if (x + a, y) in points and (x, y + b) in points and (x + a, y + b) in points:
        cnt += 1
printf(str(cnt))
