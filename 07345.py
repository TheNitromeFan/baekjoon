import sys


def multiply(f, g):
    fg = [0] * (len(f) + len(g) - 1)
    for i, x in enumerate(g):
        for j, y in enumerate(f):
            fg[i + j] += x * y
            fg[i + j] %= 2
    return fg


def divide(f, g):
    f_g = f[::]
    for i in range(len(f) - len(g) + 1):
        if f_g[i] == 0:
            continue
        for j, y in enumerate(g):
            f_g[i + j] += y
            f_g[i + j] %= 2
    return f_g[1-len(g):]


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        f = [int(x) for x in sys.stdin.readline().split()][1:]
        g = [int(x) for x in sys.stdin.readline().split()][1:]
        h = [int(x) for x in sys.stdin.readline().split()][1:]
        ans = divide(multiply(f, g), h)
        while ans and ans[0] == 0:
            ans.pop(0)
        if not ans:
            ans = [0]
        print(f"{len(ans)} {' '.join(str(x) for x in ans)}")


main()
