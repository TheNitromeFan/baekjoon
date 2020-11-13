import math


def main():
    while True:
        x, y = (int(a) for a in input().split())
        if x == 0 and y == 0:
            break
        print(int(round(math.atan2(y, x) * 180 / math.pi)))


main()
