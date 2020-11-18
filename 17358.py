import math


def main():
    n = int(input())
    print(math.factorial(n) // math.factorial(n // 2) // 2 ** (n // 2) % (10 ** 9 + 7))


main()
