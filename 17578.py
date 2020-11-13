import sys


def dist(pair1, pair2):
    return abs(pair1[0] - pair2[0]) + abs(pair1[1] - pair2[1])


def main():
    while True:
        h, w = (int(x) for x in sys.stdin.readline().split())
        keyboard = {}
        if h == 0 and w == 0:
            break
        for i in range(1, h + 1):
            line = sys.stdin.readline().rstrip()
            for j in range(1, w + 1):
                if line[j - 1] != "_":
                    keyboard[line[j - 1]] = (i, j)
        s = sys.stdin.readline().rstrip()
        pos = (1, 1)
        presses = 0
        for c in s:
            presses += dist(pos, keyboard[c]) + 1
            pos = keyboard[c]
        print(presses)


main()
