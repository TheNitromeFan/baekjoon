fibs = {}
mod = 10 ** 9
p = mod // 10 * 15


def fibonacci(x):
    x %= p
    if x == 0:
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


for i in range(int(input())):
    k, y = list(map(int, input().split()))
    print("{} {}".format(k, fibonacci(y)))
