import sys
import math


def main():
    z = int(sys.stdin.readline())
    for _ in range(z):
        k = int(sys.stdin.readline())
        while k % 2 == 0:
            k //= 2
        print(math.ceil(math.log2(k)))


main()
