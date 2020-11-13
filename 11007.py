import sys
import string


t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    outs = [int(x) for x in sys.stdin.readline().split()]
    cur = list(string.ascii_lowercase)
    ans = ""
    for out in outs:
        x = cur[out]
        cur.pop(out)
        cur = [x] + cur
        ans += x
    print(ans)
