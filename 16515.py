import math


def main():
    n = int(input())
    e = 0
    for i in range(min(50, n + 1)):
        e += 1.0 / math.factorial(i)
    print("{0:.20f}".format(e))


main()
