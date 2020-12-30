import sys
import math


n, h = (int(x) for x in sys.stdin.readline().split())
d = abs(n - h)
print(math.comb(2 * d, d) // (d + 1))
