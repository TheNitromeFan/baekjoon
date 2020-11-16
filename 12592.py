import sys
import math


def main():
    c = int(sys.stdin.readline())
    for a0 in range(1, c + 1):
        nt = [int(x) for x in sys.stdin.readline().split()]
        n, t = nt[0], nt[1:]
        val = 0
        for i in range(n - 1):
            val = math.gcd(val, t[i] - t[i + 1])
        time = -t[0] % val
        print("Case #{}: {}".format(a0, time))


main()
