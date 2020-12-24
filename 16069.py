import sys
import math


def build(m, n):
    x = 0
    i = 1
    while True:
        x += i ** n
        if x == m:
            return i
        elif x > m:
            return False
        i += 1


def main():
    m = int(sys.stdin.readline())
    if m == 1:
        print(3, 1)
        return
    for n in range(3, int(math.log2(m - 1)) + 2):
        s = build(m, n - 1)
        if s:
            print(n, s)
            return
    print("impossible")


main()
