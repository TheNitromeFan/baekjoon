import sys
import heapq


MOD = 10 ** 9 + 7
t = int(sys.stdin.readline())
for _ in range(t):
    n = int(sys.stdin.readline())
    slimes = [int(x) for x in sys.stdin.readline().split()]
    heapq.heapify(slimes)
    electricity = 1
    while len(slimes) > 1:
        x = heapq.heappop(slimes)
        y = heapq.heappop(slimes)
        prod = x * y
        electricity *= prod
        heapq.heappush(slimes, prod)
        electricity %= MOD
    print(electricity)
