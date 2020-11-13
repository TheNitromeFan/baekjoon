import math


n = int(input())
for _ in range(n):
    numbers = [int(x) for x in input().split()]
    answer = 1
    for i, x in enumerate(numbers):
        for j, y in enumerate(numbers):
            g = math.gcd(x, y)
            if i != j and answer < g:
                answer = g
    print(answer)
