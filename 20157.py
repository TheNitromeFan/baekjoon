import sys
import math


n = int(sys.stdin.readline())
balloons = {}
for _ in range(n):
    x, y = (int(z) for z in sys.stdin.readline().split())
    g = math.gcd(abs(x), abs(y))
    x //= g
    y //= g
    if (x, y) in balloons:
        balloons[(x, y)] += 1
    else:
        balloons[(x, y)] = 1
print(max(balloons.values()))
