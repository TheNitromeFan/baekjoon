import math


def main():
    t = int(input())
    for _ in range(t):
        n, k = (int(x) for x in input().split())
        print(math.factorial(n) // math.factorial(k) // math.factorial(n - k) % (10 ** 9 + 7))


main()
