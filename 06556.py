import math
import sys


while True:
    n, m = (int(x) for x in sys.stdin.readline().split())
    if n == m == 0:
        break
    print(math.comb(n + m, n))
