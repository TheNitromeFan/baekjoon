import math


n = int(input())
zeroes = int(math.log10(n))
low = n // 10 ** zeroes * 10 ** zeroes
high = low + 10 ** zeroes
if n - low < high - n:
    print(low)
else:
    print(high)
