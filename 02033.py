import math


def main():
    n = int(input())
    i = 1
    while True:
        ten_power = 10 ** i
        if n <= ten_power:
            break
        round_up, round_down = math.ceil(n / ten_power) * ten_power, math.floor(n / ten_power) * ten_power
        if round_up - n <= n - round_down:
            n = round_up
        else:
            n = round_down
        i += 1
    print(n)


main()
