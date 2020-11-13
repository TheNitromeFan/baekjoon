import math
import sys


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        n = int(sys.stdin.readline())
        print(str(math.factorial(n)).rstrip("0")[-1])


main()
