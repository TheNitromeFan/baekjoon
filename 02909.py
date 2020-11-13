import math


def main():
    c, k = (int(x) for x in input().split())
    bill = 10 ** k
    up_price, down_price = math.ceil(c / bill) * bill, math.floor(c / bill) * bill
    if up_price - c <= c - down_price:
        print(up_price)
    else:
        print(down_price)


main()
