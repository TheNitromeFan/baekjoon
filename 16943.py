import sys
import itertools


a, b = sys.stdin.readline().rstrip().split()
a_digits = sorted(a)
cmp = int(b)
ans = -1
for perm in itertools.permutations(a_digits):
    if perm[0] == "0":
        continue
    x = int("".join(perm))
    if ans < x <= cmp:
        ans = x
print(ans)
