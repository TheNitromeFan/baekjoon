import sys


def distance(r, s):
    cnt = 0
    for c, d in zip(r, s):
        if c != d:
            cnt += 1
    return cnt


def minimum_distance(codes, r):
    return min(distance(r, code) for code in codes)


def main():
    k = int(sys.stdin.readline())
    for t in range(1, k + 1):
        n, b = (int(x) for x in sys.stdin.readline().split())
        codes = []
        for _ in range(n):
            codes.append(sys.stdin.readline().rstrip())
        r = sys.stdin.readline().rstrip()
        sys.stdout.write("Data Set {}:\n{}\n\n".format(t, minimum_distance(codes, r)))


main()
