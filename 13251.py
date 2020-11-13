import sys
import math


def main():
    f = math.factorial
    sys.stdin.readline()
    color_counts = [int(x) for x in sys.stdin.readline().rstrip().split()]
    n = sum(color_counts)
    k = int(sys.stdin.readline())
    total = f(n) // f(k) // f(n - k)
    event = 0
    for color_count in color_counts:
        if color_count >= k:
            event += f(color_count) // f(k) // f(color_count - k)
    print(event / total)


main()
