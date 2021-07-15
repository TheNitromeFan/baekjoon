import sys


x = int(sys.stdin.readline())
n = int(sys.stdin.readline())
scores = []
points = {}
for _ in range(n):
    entries = sys.stdin.readline().split()
    party, g = entries[0], int(entries[1])
    if 20 * g >= x:
        points[party] = 0
        for i in range(1, 15):
            scores.append((party, g / i))
scores.sort(key=lambda y: -y[1])
for party, _ in scores[:14]:
    points[party] += 1
for party, point in sorted(points.items()):
    print(party, point)
