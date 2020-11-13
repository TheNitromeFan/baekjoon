import sys


t = int(sys.stdin.readline())
for _ in range(t):
    names = sys.stdin.readline().rstrip().split()
    p = len(names)
    start = sys.stdin.readline().rstrip()
    n = int(sys.stdin.readline())
    i = names.index(start)
    print(names[(i + n - 1) % p])
