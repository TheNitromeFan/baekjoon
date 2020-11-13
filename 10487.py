import sys


def expr(n):
    ops = [" + ", " - ", " * ", " // "]
    for op1 in ops:
        for op2 in ops:
            for op3 in ops:
                expression = "4" + op1 + "4" + op2 + "4" + op3 + "4"
                try:
                    if eval(expression) == n:
                        return "{} = {}".format(expression, n).replace("//", "/")
                except ZeroDivisionError:
                    continue
    return "no solution"


def main():
    m = int(sys.stdin.readline())
    for _ in range(m):
        print(expr(int(sys.stdin.readline())))


main()
