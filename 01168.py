import sys


n, k = (int(x) for x in sys.stdin.readline().split())
k -= 1
a = list(range(1, n + 1))
idx = 0
sys.stdout.write("<")
ans = []
for i in range(n):
    idx = (idx + k) % len(a)
    ans.append(a[idx])
    a = a[:idx] + a[idx + 1:]
sys.stdout.write(", ".join(str(x) for x in ans))
sys.stdout.write(">")
