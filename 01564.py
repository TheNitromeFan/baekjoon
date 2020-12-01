def factorial(n):
    ret = 1
    for i in range(1, n + 1):
        ret *= i
        while ret % 10 == 0:
            ret //= 10
        ret %= 10 ** 15
    return ret


n = int(input())
print(str(factorial(n)).rstrip("0")[-5:])
