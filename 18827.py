import sys


n = int(sys.stdin.readline())
nums = [int(x) for x in sys.stdin.readline().split()]
best_sum = -float('INF')
current_sum = 0
for x in nums:
    current_sum = max(x, current_sum + x)
    best_sum = max(best_sum, current_sum)
print(best_sum)
