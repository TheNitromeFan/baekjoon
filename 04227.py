import sys


def main():
    for line in sys.stdin.readlines():
        line = line.rstrip()
        if line == "()" or line == "":
            break
        stack = []
        cur = ""
        for c in line:
            if c == "(":
                stack.append("(")
                cur = ""
            elif c == ")":
                if cur:
                    stack.append(float(cur))
                    cur = ""
                y = stack.pop()
                x = stack.pop()
                p = stack.pop()
                stack.pop()
                stack.append(x + (2 * p - 1) * y)
            elif c == " " and cur:
                stack.append(float(cur))
                cur = ""
            else:
                cur += c
        if cur:
            stack.append(float(cur))
        if len(stack) != 1:
            while True:
                pass
        sys.stdout.write("{0:.2f}\n".format(stack[0]))


main()
