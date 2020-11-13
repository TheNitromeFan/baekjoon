fibs = {0:[1, 0, 0, 1], 1:[1, 1, 1, 0]}

def multiply(a, b):
    return [a[0] * b[0] + a[1] * b[2], a[0] * b[1] + a[1] * b[3], a[2] * b[0] + a[3] * b[2], a[2] * b[1] + a[3] * b[3]]


def fibonacci(n):
    if n == 0 or n == 1:
        return
    if n % 2 == 0:
        fibonacci(n // 2)
        fibs[n] = multiply(fibs[n//2], fibs[n//2])
    else:
        fibonacci(n // 2)
        fibonacci(n // 2 + 1)
        fibs[n] = multiply(fibs[n//2], fibs[n//2 + 1])


def main():
    n = int(input())
    fibonacci(n)
    print(fibs[n][1])


main()
