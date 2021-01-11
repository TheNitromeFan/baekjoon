import sys


n = int(sys.stdin.readline())
key = {}
for _ in range(n):
    letter, code = sys.stdin.readline().rstrip().split()
    key[code] = letter
seq = sys.stdin.readline().rstrip()
cur = ""
ans = ""
for c in seq:
    cur += c
    if cur in key:
        ans += key[cur]
        cur = ""
print(ans)
