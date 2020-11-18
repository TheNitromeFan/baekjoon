import sys


def main():
    n, m = (int(x) for x in sys.stdin.readline().split())
    paths = {}
    for _ in range(m):
        a, b, c, d = (int(x) for x in sys.stdin.readline().split())
        paths[(a, b)] = (c, d)
    times1, times2 = {1: {0}}, {1: {0}}
    for i in range(2, n + 1):
        times1[i], times2[i] = set(), set()
        for j in range(1, i):
            if (j, i) in paths:
                times1[i] |= {x + paths[(j, i)][0] for x in times1[j]}
                times2[i] |= {x + paths[(j, i)][1] for x in times2[j]}
    s = times1[n] & times2[n]
    if s:
        sys.stdout.write("{}".format(min(s)))
    else:
        sys.stdout.write("IMPOSSIBLE")


main()
