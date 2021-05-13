import sys


def zap(pivots):
    count = 0
    while len(pivots) > 1:
        if all(pivot == 0 for pivot in pivots):
            print("z" * count + "ap!")
            return
        new_pivots = pivots[1:]
        for i in range(len(new_pivots)):
            new_pivots[i] -= pivots[i]
        pivots = new_pivots[::]
        count += 1
    if pivots[0] == 0:
        print("z" * count + "ap!")
    elif pivots[0] > 0:
        print("*fizzle*")
    else:
        print("*bunny*")


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        entries = [int(x) for x in sys.stdin.readline().split()]
        pivots = entries[1:]
        zap(pivots)


main()
