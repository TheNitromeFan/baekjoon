import math
import sys
import decimal


t = int(sys.stdin.readline())
for i in range(1, t + 1):
    v, d = (int(x) for x in sys.stdin.readline().split())
    try:
        sys.stdout.write(f"Case #{i}: {math.asin(decimal.Decimal(9.8) * d / (v ** 2)) * 180 / math.tau}\n")
    except ValueError:
        sys.stdout.write(f"Case #{i}: 0.0000000\n")
