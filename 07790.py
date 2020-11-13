import sys


ans = 0
for line in sys.stdin:
    ans += line.count("joke")
print(ans)
