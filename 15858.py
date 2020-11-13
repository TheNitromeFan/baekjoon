from decimal import Decimal, getcontext

getcontext().prec = 50
a, b, c = (Decimal(x) for x in input().split())
print("{0:.10f}".format(a * b / c))
