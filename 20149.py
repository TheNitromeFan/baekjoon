import sys
from decimal import Decimal, getcontext


getcontext().prec = 20


def equals(decimal1, decimal2):
    return abs(decimal1 - decimal2) <= 10 ** -20


def ccw(x1, y1, x2, y2, x3, y3):
    cmp = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1)
    if equals(cmp, Decimal(0)):
        return 0
    elif cmp > 0:
        return 1
    else:
        return -1


def meet(a, b, c, d):
    if a > b:
        a, b = b, a
    if c > d:
        c, d = d, c
    if b == c:
        return 1, b
    elif a == d:
        return 1, a
    elif b < c or d < a:
        return 0,
    return 2,


def intersect(x1, y1, x2, y2, x3, y3, x4, y4):
    cmp1 = ccw(x1, y1, x2, y2, x3, y3)
    cmp2 = ccw(x1, y1, x2, y2, x4, y4)
    cmp3 = ccw(x3, y3, x4, y4, x1, y1)
    cmp4 = ccw(x3, y3, x4, y4, x2, y2)
    if cmp1 == 0 and cmp2 == 0:
        ans1, ans2 = meet(x1, x2, x3, x4), meet(y1, y2, y3, y4)
        print(int(ans1[0] > 0 and ans2[0] > 0))
        if ans1[0] == 1 and ans2[0] == 1:
            print(ans1[1], ans2[1])
    elif cmp1 == 0:
        print(int(cmp3 * cmp4 <= 0))
        if cmp3 * cmp4 <= 0:
            print(x3, y3)
    elif cmp2 == 0:
        print(int(cmp3 * cmp4 <= 0))
        if cmp3 * cmp4 <= 0:
            print(x4, y4)
    elif cmp3 == 0:
        print(int(cmp1 * cmp2 <= 0))
        if cmp1 * cmp2 <= 0:
            print(x1, y1)
    elif cmp4 == 0:
        print(int(cmp1 * cmp2 <= 0))
        if cmp1 * cmp2 <= 0:
            print(x2, y2)
    else:
        print(int(cmp1 * cmp2 <= 0 and cmp3 * cmp4 <= 0))
        if cmp1 * cmp2 <= 0 and cmp3 * cmp4 <= 0:
            for _ in range(1000):
                xmid, ymid = (x1 + x2) / 2, (y1 + y2) / 2
                if ccw(x3, y3, x4, y4, xmid, ymid) == 0:
                    break
                elif ccw(x3, y3, x4, y4, xmid, ymid) * ccw(x3, y3, x4, y4, x1, y1) > 0:
                    x1, y1 = xmid, ymid
                else:
                    x2, y2 = xmid, ymid
            print(xmid, ymid)


x1, y1, x2, y2 = (Decimal(z) for z in sys.stdin.readline().rstrip().split())
x3, y3, x4, y4 = (Decimal(z) for z in sys.stdin.readline().rstrip().split())
intersect(x1, y1, x2, y2, x3, y3, x4, y4)
