import sys
import itertools


n = int(sys.stdin.readline())
codes = set()
pairs = {}
for _ in range(n):
    city, state = sys.stdin.readline().rstrip().split()
    city = city[:2]
    codes.add(city)
    codes.add(state)
    if (city, state) not in pairs:
        pairs[(city, state)] = 0
    pairs[(city, state)] += 1
ans = 0
for u, v in itertools.combinations(codes, 2):
    if (u, v) in pairs and (v, u) in pairs:
        ans += pairs[(u, v)] * pairs[(v, u)]
print(ans)
