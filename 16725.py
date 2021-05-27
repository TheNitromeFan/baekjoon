import sys
import math


n, m, k = (int(x) for x in sys.stdin.readline().split())
ans = 0
for i in range(k // (n + 1) + 1):
    ans += (-1) ** i * math.comb(m, i) * math.comb(m + k - (n + 1) * i - 1, m - 1)
    ans %= 10 ** 9 + 9
print(ans)
