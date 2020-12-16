import sys
import decimal


decimal.getcontext().prec = 10
decimals = {}
for n in range(1, 1001):
    decimals[n] = set()
    for i in range(n):
        x = decimal.Decimal(i) / decimal.Decimal(n)
        after_decimal_point = str(x)[1:5].ljust(4, '0')
        if after_decimal_point[0] == '0':
            after_decimal_point = '.' + after_decimal_point[1:]
        decimals[n].add(after_decimal_point)
n = int(sys.stdin.readline())
lines = []
for _ in range(n):
    line = sys.stdin.readline().rstrip()
    lines.append(line[line.index("."):])
k = 1
while True:
    if all(line in decimals[k] for line in lines):
        print(k)
        break
    k += 1
