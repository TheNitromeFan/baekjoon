from math import gcd


a, b = [int(x) for x in input().split()]
print(a // gcd(a, b) * b)
