import sys
import fractions
import itertools


n = int(sys.stdin.readline())
slopes = {}
for _ in range(n):
    a, b, _ = (int(x) for x in sys.stdin.readline().split())
    if b:
        f = fractions.Fraction(a, b)
    else:
        f = float('inf')
    if f in slopes:
        slopes[f] += 1
    else:
        slopes[f] = 1
print(sum(a * b for a, b in itertools.combinations(slopes.values(), 2)))