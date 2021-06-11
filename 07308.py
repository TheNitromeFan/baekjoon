import sys
import math


def parse(expression):
    a, b = 0, 0
    sign = 1
    s = ""
    idx = 0
    while idx < len(expression):
        if expression[idx] in "+-":
            if s == "x":
                if sign == 1:
                    a += 1
                else:
                    a -= 1
            elif s[-1] == "x":
                if sign == 1:
                    a += int(s[:-1])
                else:
                    a -= int(s[:-1])
            else:
                if sign == 1:
                    b += int(s)
                else:
                    b -= int(s)
            s = ""
            if expression[idx] == "+":
                sign = 1
            else:
                sign = -1
        else:
            s += expression[idx]
        idx += 1
    if s == "x":
        if sign == 1:
            a += 1
        else:
            a -= 1
    elif s[-1] == "x":
        if sign == 1:
            a += int(s[:-1])
        else:
            a -= int(s[:-1])
    else:
        if sign == 1:
            b += int(s)
        else:
            b -= int(s)
    return a, b


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        equation = sys.stdin.readline().rstrip()
        left, right = equation.split("=")
        a, b = parse(left)
        c, d = parse(right)
        if a != c:
            print(int(math.floor((d - b) / (a - c) + 0.0000005)))
        elif b == d:
            print("IDENTITY")
        else:
            print("IMPOSSIBLE")


main()
