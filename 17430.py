import sys


t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    xy, x, y = set(), set(), set()
    for i in range(n):
        xi, yi = (int(z) for z in sys.stdin.readline().split())
        xy.add((xi, yi))
        x.add(xi)
        y.add(yi)
    if len(xy) == len(x) * len(y):
        sys.stdout.write("BALANCED\n")
    else:
        sys.stdout.write("NOT BALANCED\n")
