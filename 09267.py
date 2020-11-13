def xgcd(a, b):
    x0, x1, y0, y1 = 0, 1, 1, 0
    while a != 0:
        (q, a), b = divmod(b, a), a
        y0, y1 = y1, y0 - q * y1
        x0, x1 = x1, x0 - q * x1
    return b, x0, y0


def can_solve(a, b, s):
    if a == 0 and b == 0:
        return s == 0
    elif a == 0:
        return s % b == 0
    elif b == 0:
        return s % a == 0
    g, x, y = xgcd(a, b)
    if s % g != 0:
        return False
    x *= s // g
    y *= s // g
    for k in range(-g * x // b + 1, g * y // a + 1):
        if xgcd(x + k * b // g, y - k * a // g)[0] == 1:
            return True
    return False


def main():
    a, b, s = (int(x) for x in input().split())
    if can_solve(a, b, s):
        print("YES")
    else:
        print("NO")


main()
