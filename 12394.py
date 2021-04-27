import sys


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        a, b = (int(x) for x in sys.stdin.readline().split())
        p = [1.0] + [float(x) for x in sys.stdin.readline().split()]
        strokes = b + 2
        prod = 1
        for d, pi in enumerate(p):
            prod *= pi
            y = (b + 1) * (1 - prod) + b - 2 * d + a + 1
            strokes = min(strokes, y)
        sys.stdout.write("Case #{0}: {1:.6f}\n".format(a0, strokes))


main()
