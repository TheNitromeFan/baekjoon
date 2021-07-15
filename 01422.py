import sys
import functools


k, n = (int(x) for x in sys.stdin.readline().split())
v = []
for _ in range(k):
    v.append(int(sys.stdin.readline()))
v.sort(reverse=True)
for _ in range(n - k):
    v.append(v[0])
v.sort(key=functools.cmp_to_key(lambda a, b: -1 if int(str(a) + str(b)) > int(str(b) + str(a)) else 1))
print("".join(str(x) for x in v))
