import math


n = int(input())
for _ in range(n):
    m = int(input())
    log_factorial = 0
    for i in range(1, m + 1):
        log_factorial += math.log10(i)
    print(int(log_factorial) + 1)
