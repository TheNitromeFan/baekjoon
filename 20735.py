import sys


n = int(sys.stdin.readline())
ans = 0
for _ in range(n):
    name = sys.stdin.readline().rstrip().lower()
    if "pink" in name or "rose" in name:
        ans += 1
if ans:
    print(ans)
else:
    print("I must watch Star Wars with my daughter")
