import sys


for line in sys.stdin:
    m, p, larvae, e, r, s, n = (int(x) for x in line.split())
    for _ in range(n):
        m, p, larvae = p // s, larvae // r, m * e
    print(m)
