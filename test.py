import string
import math
import itertools


fibs = {}


def fib(n):
    if n in [1, 2]:
        return 1
    elif n in fibs:
        return fibs[n]
    elif n % 2 == 0:
        x = fib(n // 2)
        y = fib(n // 2 - 1)
        fibs[n] = x * (x + 2 * y)
    else:
        x = fib(n // 2)
        y = fib(n // 2 + 1)
        fibs[n] = x * x + y * y
    return fibs[n]


print(math.log10(fib(110000)))

