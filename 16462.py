import sys


n = int(sys.stdin.readline())
ans = 0
for _ in range(n):
    score = int(sys.stdin.readline().replace('0', '9').replace('6', '9'))
    ans += min(score, 100)
print(round(ans / n + 10 ** -9))
