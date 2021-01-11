import sys
import string


s = sys.stdin.readline().rstrip()
p = sys.stdin.readline().rstrip()
pis = {x: s.count(x) for x in string.ascii_lowercase}
pip = {x: p.count(x) for x in string.ascii_lowercase}
if all(pis[x] >= pip[x] for x in string.ascii_lowercase):
    sys.stdout.write("YES")
else:
    sys.stdout.write("NO")
