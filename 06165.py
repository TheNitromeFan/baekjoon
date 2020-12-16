import sys
import math


n = int(sys.stdin.readline())
points = []
for _ in range(n):
    points.append(tuple(int(z) for z in sys.stdin.readline().split()))
slopes = set()
for i in range(n):
    for j in range(i):
        x, y = points[i][0] - points[j][0], points[i][1] - points[j][1]
        if x < 0 or (x == 0 and y < 0):
            x, y = -x, -y
        g = math.gcd(x, y)
        slopes.add((x // g, y // g))
print(len(slopes))
