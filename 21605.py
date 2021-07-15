import sys


n = int(sys.stdin.readline())
a = [0 for _ in range(2 * n + 1)]
x = 2 * n
p, m = 0, 0
for i in range(n):
    if i % 4 in [0, 3]:
        a[x - 2 * i] = 1
        p += 1
    else:
        a[x - 2 * i] = -1
        m += 1
for i in range(n - 1):
    y = x - 1 - 2 * i
    a[y] = a[y + 1] // a[y - 1]
    if a[y] == 1:
        p += 1
    else:
        m += 1
if p == n:
    a[1] = -1
    m += 1
else:
    a[1] = 1
    p += 1
assert p == m == n
print(" ".join(str(x) for x in a[1:]))
