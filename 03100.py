import sys
import collections


def main():
    color = {}
    for i in range(6):
        line = sys.stdin.readline().rstrip()
        for j in range(9):
            color[(i, j)] = line[j]
    ans = 6 * 9
    colors1 = collections.Counter(color[(i, j)] for i in range(0, 2) for j in range(9))
    colors2 = collections.Counter(color[(i, j)] for i in range(2, 4) for j in range(9))
    colors3 = collections.Counter(color[(i, j)] for i in range(4, 6) for j in range(9))
    for color1 in colors1:
        for color2 in colors2:
            for color3 in colors3:
                if color1 == color2 or color2 == color3:
                    ans = min(ans, 54 - colors1[color1] - colors3[color3])
                else:
                    ans = min(ans, 54 - colors1[color1] - colors2[color2] - colors3[color3])
    colors1 = collections.Counter(color[(i, j)] for i in range(6) for j in range(0, 3))
    colors2 = collections.Counter(color[(i, j)] for i in range(6) for j in range(3, 6))
    colors3 = collections.Counter(color[(i, j)] for i in range(6) for j in range(6, 9))
    for color1 in colors1:
        for color2 in colors2:
            for color3 in colors3:
                if color1 == color2 or color2 == color3:
                    ans = min(ans, 54 - colors1[color1] - colors3[color3])
                else:
                    ans = min(ans, 54 - colors1[color1] - colors2[color2] - colors3[color3])

    print(ans)


main()
