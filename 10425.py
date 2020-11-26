import sys


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


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        fn = int(sys.stdin.readline())
        low, high = 2, 110000
        while low <= high:
            mid = (low + high) // 2
            if fib(mid) == fn:
                break
            elif fib(mid) <= fn:
                low = mid + 1
            else:
                high = mid - 1
        sys.stdout.write("{}\n".format(mid))


main()
