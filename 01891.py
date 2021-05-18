import sys


def main():
    entries = sys.stdin.readline().rstrip().split()
    d, sequence = int(entries[0]), entries[1]
    x, y = 0, 0
    for ind, k in enumerate(sequence):
        if k == "1":
            x += 2 ** (d - 1 - ind)
            y += 2 ** (d - 1 - ind)
        elif k == "2":
            x -= 2 ** (d - 1 - ind)
            y += 2 ** (d - 1 - ind)
        elif k == "3":
            x -= 2 ** (d - 1 - ind)
            y -= 2 ** (d - 1 - ind)
        elif k == "4":
            x += 2 ** (d - 1 - ind)
            y -= 2 ** (d - 1 - ind)
    dx, dy = (int(z) for z in sys.stdin.readline().split())
    x += dx * 2
    y += dy * 2
    if not (-2 ** d < x < 2 ** d and -2 ** d < y < 2 ** d):
        print(-1)
        return
    # print(x, y)
    for ind in range(d):
        if x > 0 and y > 0:
            print(1, end="")
            x -= 2 ** (d - 1 - ind)
            y -= 2 ** (d - 1 - ind)
        elif y > 0:
            print(2, end="")
            x += 2 ** (d - 1 - ind)
            y -= 2 ** (d - 1 - ind)
        elif x < 0 and y < 0:
            print(3, end="")
            x += 2 ** (d - 1 - ind)
            y += 2 ** (d - 1 - ind)
        else:
            print(4, end="")
            x -= 2 ** (d - 1 - ind)
            y += 2 ** (d - 1 - ind)


main()
