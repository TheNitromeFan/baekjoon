import sys


def main():
    n = int(sys.stdin.readline())
    x = [int(y) for y in sys.stdin.readline().split()]
    a = list(set(x))
    a.sort()
    d = {val: ind for ind, val in enumerate(a)}
    sys.stdout.write(" ".join(str(d[xi]) for xi in x))


main()
