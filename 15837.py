import sys


t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    print(((n * (n + 1) * (n + 2)) // 6) ** 2)
