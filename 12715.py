import sys


t = int(sys.stdin.readline())
for a0 in range(1, t + 1):
    n, m, x, y, z = (int(w) for w in sys.stdin.readline().split())
    a = []
    for _ in range(m):
        a.append(int(sys.stdin.readline()))
    for i in range(m, n):
        a.append((x * a[i - m] + y * (i - m + 1)) % z)
    dp = [1 for _ in range(n)]
    for i in range(n):
        for j in range(i):
            if a[j] < a[i]:
                dp[i] += dp[j]
    print(f"Case #{a0}: {sum(dp) % (10 ** 9 + 7)}")
