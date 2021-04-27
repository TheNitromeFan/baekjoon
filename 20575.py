import sys


n = int(sys.stdin.readline())
cnt = 0
for _ in range(n):
    x1, _, x2, _ = sys.stdin.readline().split()
    if x1[:x1.index(".")] != x2[:x2.index(".")]:
        cnt += 1
print(2 * n / cnt)
