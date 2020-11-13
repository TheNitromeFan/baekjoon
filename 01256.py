from math import factorial


def combination(n, k):
    return factorial(n) // factorial(k) // factorial(n-k)


def main():
    n, m, k = (int(x) for x in input().split())
    if k > combination(n+m, n):
        print(-1)
        return
    length = n + m
    output = ""
    for _ in range(length):
        if n == 0:
            output += "z"
            m -= 1
        elif m == 0:
            output += "a"
            n -= 1
        elif k > combination(n+m-1, n-1):
            output += "z"
            k -= combination(n+m-1, n-1)
            m -= 1
        else:
            output += "a"
            n -= 1
    print(output)


main()
