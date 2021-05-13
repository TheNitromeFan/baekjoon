import sys
import math


def main():
    small_factorials = ["1", "2", "6", "24", "120", "720"]
    s = sys.stdin.readline().rstrip()
    if s in small_factorials:
        print(small_factorials.index(s) + 1)
        return
    digits = len(s)
    n = 1
    sum_of_log10s = 0
    while True:
        sum_of_log10s += math.log10(n)
        if sum_of_log10s < digits < sum_of_log10s + 1:
            break
        n += 1
    print(n)


main()
