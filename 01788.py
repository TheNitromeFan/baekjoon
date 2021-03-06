fibs = {}
mod = 10 ** 9
p = mod // 10 * 15


def sign(x):
    if x == 0:
        return 0
    elif x > 0 or x & 1 == 1:
        return 1
    return -1


def fibonacci(x):
    if x < 0:
        return fibonacci(-x)
    elif x == 0:
        return 0
    elif x in [1, 2]:
        return 1
    elif x in fibs.keys():
        return fibs[x]
    if x % 2 == 0:
        f1, f2 = fibonacci(x//2 - 1), fibonacci(x//2)
        fibs[x] = (2*f1 + f2) * f2 % mod
    else:
        f1, f2 = fibonacci(x//2), fibonacci(x//2 + 1)
        fibs[x] = (f1**2 + f2**2) % mod
    return fibs[x]


n = int(input())
print(sign(n))
print(fibonacci(n))
