import sys


def main():
    points = [(x, y) for x in range(1, 151) for y in range(x + 1, 151)]
    points.sort(key=lambda x: (x[0] ** 2 + x[1] ** 2, x[0]))
    while True:
        h, w = (int(x) for x in sys.stdin.readline().split())
        if h == 0 and w == 0:
            break
        print(" ".join(str(x) for x in points[points.index((h, w)) + 1]))


main()
