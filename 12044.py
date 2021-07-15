import sys


t = int(sys.stdin.readline())
for a0 in range(1, t + 1):
    n, k = (int(x) for x in sys.stdin.readline().split())
    a = [int(x) for x in sys.stdin.readline().split()]
    b = [int(x) for x in sys.stdin.readline().split()]
    c = [int(x) for x in sys.stdin.readline().split()]
    d = [int(x) for x in sys.stdin.readline().split()]
    ab = {}
    for ai in a:
        for bj in b:
            x = ai ^ bj ^ k
            if x in ab:
                ab[x] += 1
            else:
                ab[x] = 1
    ans = 0
    for ck in c:
        for dl in d:
            y = ck ^ dl
            if y in ab:
                ans += ab[y]
    print(f"Case #{a0}: {ans}")
