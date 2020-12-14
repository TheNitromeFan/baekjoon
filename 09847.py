import sys
import itertools


def main():
    a, b, c, d = (int(x) for x in sys.stdin.readline().split())
    list1, list2 = [], []
    for _ in range(a):
        list1.append(int(sys.stdin.readline()))
    for _ in range(b):
        list2.append(int(sys.stdin.readline()))
    sums1 = sorted([(x, y, x + y) for x in list1 for y in list2], key=lambda z: z[2])
    list1, list2 = [], []
    for _ in range(c):
        list1.append(int(sys.stdin.readline()))
    for _ in range(d):
        list2.append(int(sys.stdin.readline()))
    sums2 = sorted([(x, y, x + y) for x in list1 for y in list2], key=lambda z: z[2], reverse=True)
    i, j = 0, 0
    while i < a * b and j < c * d:
        x1, y1, sum1 = sums1[i]
        x2, y2, sum2 = sums2[j]
        if sum1 + sum2 == 0:
            sys.stdout.write("{} {} {} {}".format(x1, y1, x2, y2))
            return
        if i == a * b:
            j += 1
        elif j == c * d:
            i += 1
        elif sum1 + sum2 < 0:
            i += 1
        else:
            j += 1


main()
