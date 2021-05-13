import sys


def main():
    n = int(sys.stdin.readline())
    power_of_5 = 5
    ans = 0
    while power_of_5 <= n:
        m = (n + 1) // power_of_5
        ans += (n + 1) * m - power_of_5 * m * (m + 1) // 2
        power_of_5 *= 5
    print(ans)


main()
