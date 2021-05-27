import sys


def efficient(n, c, t, r):
    return c * t * 10080 >= n * (t + r)


def main():
    n, m = (int(x) for x in sys.stdin.readline().split())
    lawn_mowers = []
    for _ in range(m):
        name, p, c, t, r = sys.stdin.readline().split(",")
        p, c, t, r = int(p), int(c), int(t), int(r)
        if not efficient(n, c, t, r):
            continue
        if not lawn_mowers or lawn_mowers[0][1] > p:
            lawn_mowers = [(name, p)]
        elif lawn_mowers[0][1] == p:
            lawn_mowers.append((name, p))
    if lawn_mowers:
        print("\n".join(x[0] for x in lawn_mowers))
    else:
        print("no such mower")


main()
