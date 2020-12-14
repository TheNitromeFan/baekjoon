import sys
import math


sys.stdin.readline()
a = [int(x) for x in sys.stdin.readline().split()]
numerator = 1
for x in a:
    numerator *= x
denominator = 0
for x in a:
    denominator += numerator // x
g = math.gcd(numerator, denominator)
sys.stdout.write("{}/{}".format(numerator // g, denominator // g))
