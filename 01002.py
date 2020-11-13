def points(x1, y1, r1, x2, y2, r2):
    d = ((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5
    if d == 0 and r1 == r2:
        return -1
    elif d < abs(r1 - r2) or d > r1 + r2:
        return 0
    elif d == abs(r1 - r2) or d == r1 + r2:
        return 1
    else:
        return 2


def main():
    x1, y1, r1, x2, y2, r2 = [int(a) for a in input().split()]
    print(points(x1, y1, r1, x2, y2, r2))


for i in range(int(input())):
    main()
