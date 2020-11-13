import sys


memo = [0] * 1000001
for i in range(1, 1000001):
    for j in range(1, 1000000 // i + 1):
        memo[j * i] += i
    memo[i] += memo[i - 1]
t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    print(memo[n])
