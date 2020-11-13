from decimal import Decimal, getcontext, ROUND_HALF_UP


def main():
    getcontext().prec = 1000
    getcontext().rounding = ROUND_HALF_UP
    n, bad = (int(x) for x in input().split())
    p = [Decimal(x) for x in input().split()]
    current = [Decimal(0), Decimal(0)]
    current[bad] = Decimal(1)
    for _ in range(n):
        current = [current[0] * p[0] + current[1] * p[2], current[0] * p[1] + current[1] * p[3]]
    print((current[0] * 1000).to_integral_value())
    print((current[1] * 1000).to_integral_value())


main()
