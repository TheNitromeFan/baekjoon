import sys


t = int(sys.stdin.readline())
for _ in range(t):
    s = sys.stdin.readline().rstrip()
    ans = 0
    if "0" in s:
        ans += 1
    if "1" in s:
        ans += 1
    print(ans)
