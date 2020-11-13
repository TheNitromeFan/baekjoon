from decimal import Decimal, getcontext


def main():
    getcontext().prec = 1500
    a, b = input().split()
    a, b = Decimal(a), Decimal(b)
    print(a / b)


main()
