import sys


cache = {}


n0 = -1


def f(n, end):
    if end > n:
        end = n
    global n0
    if n == n0 and end in cache:
        return cache[end]
    if n0 == -1:
        n0 = n
    ret = 0
    i = 1
    while i <= end and i <= n:
        j = n // (n // i)
        if j > end:
            j = end
        ret += (j - i + 1) * (n // i)
        if n == n0:
            cache[j] = ret
        i = j + 1
    if n0 == n:
        cache[end] = ret
    return ret


q = int(sys.stdin.readline())
for _ in range(q):
    n, s, e = (int(x) for x in sys.stdin.readline().split())
    if s > e:
        print(0)
    else:
        print(f(n, e) - f(n, s - 1))
