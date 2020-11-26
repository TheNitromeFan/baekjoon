import sys
import math


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        months, days_per_month, days_per_week = (int(x) for x in sys.stdin.readline().split())
        months_to_fit = days_per_week // math.gcd(days_per_month, days_per_week)
        q, r = divmod(months, months_to_fit)
        weeks = ((days_per_month + days_per_week) * months_to_fit // days_per_week - 1) * q + \
                (days_per_month + days_per_week) * r // days_per_week
        sys.stdout.write("Case #{}: {}\n".format(a0, weeks))


main()
