import sys


n = int(sys.stdin.readline().rstrip())
for _ in range(n):
    k, s = sys.stdin.readline().rstrip().split()
    try:
        o = int(s, base=8)
    except ValueError:
        o = 0
    print("{} {} {} {}".format(k, o, int(s, base=10), int(s, base=16)))
