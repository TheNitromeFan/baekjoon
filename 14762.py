import sys
import math


def combination(n, r):
    return math.factorial(n) // math.factorial(r) // math.factorial(n - r)


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        n, v1, v2, w = (int(x) for x in sys.stdin.readline().split())
        votes = n - v1 - v2
        d = 2 ** votes
        num = 0
        for i in range(votes, max((votes - v1 + v2) // 2, -1), -1):
            num += combination(votes, i)
        if num * 100 > d * w:
            print("GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!")
        elif num == 0:
            print("RECOUNT!")
        else:
            print("PATIENCE, EVERYONE!")


main()
