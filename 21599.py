import sys


n = int(sys.stdin.readline())
a = [int(x) for x in sys.stdin.readline().split()]
a.sort(reverse=True)
print(min(n, max(a[i] + i if a[i] else 0 for i in range(n))))
