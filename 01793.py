import sys

t = {}


def tiles(x):
    if x in [0, 1]:
        return 1
    elif x not in t:
        t[x] = tiles(x-1) + 2*tiles(x-2)
    return t[x]


for line in sys.stdin:
    print(tiles(int(line)))
