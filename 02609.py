from math import gcd


a, b = [int(x) for x in input().split()]
g = gcd(a, b)
print(g)
print(a // g * b)
