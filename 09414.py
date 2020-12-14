import sys


def price(lands, budget):
    ret = 0
    for i, land in enumerate(sorted(lands, reverse=True), start=1):
        ret += 2 * land ** i
        if ret > budget:
            return "Too expensive"
    return ret


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        lands = []
        while True:
            land = int(sys.stdin.readline())
            if land == 0:
                break
            lands.append(land)
        sys.stdout.write("{}\n".format(price(lands, 5 * 10 ** 6)))


main()
