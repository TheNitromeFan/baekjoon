import sys

n = int(sys.stdin.readline())
passports1 = {sys.stdin.readline() for _ in range(n)}
m = int(sys.stdin.readline())
passports2 = [sys.stdin.readline() for _ in range(m)]
ans = 0
for passport in passports2:
    if passport in passports1:
        ans += 1
print(ans)
