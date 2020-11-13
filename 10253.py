import math


def main():
    t = int(input())
    for _ in range(t):
        a, b = (int(x) for x in input().split())
        while a > 1:
            x = b // a + 1
            a, b = a * x - b, b * x
            a, b = a // math.gcd(a, b), b // math.gcd(a, b)
        print(b)


main()
