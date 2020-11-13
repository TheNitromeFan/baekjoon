def sum_of_factorials(n):
    if n == 0:
        return False
    factorial = 1
    i = 1
    while factorial <= n:
        i += 1
        factorial *= i
    factorial //= i
    i -= 1
    while n >= 6:
        if n >= factorial * 2:
            return False
        elif n >= factorial:
            n -= factorial
        factorial //= i
        i -= 1
    return n < 5


def main():
    n = int(input())
    if sum_of_factorials(n):
        print("YES")
    else:
        print("NO")


main()
