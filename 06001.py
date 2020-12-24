import sys


n, a, b, c, d, e, f, g, h, m = (int(x) for x in sys.stdin.readline().split())
cows = []
for i in range(3 * n):
    wi = (a * i ** 5 + b * i ** 2 + c) % d
    ui = (e * i ** 5 + f * i ** 3 + g) % h
    cows.append((wi, ui))
cows.sort(key=lambda x: (-x[1], x[0]))
sum_of_weights = sum(cow[0] for cow in cows[:n])
print(sum_of_weights % m)
