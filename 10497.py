import sys


def hit(target, x, y):
    if target[0] == "rectangle":
        return target[1] <= x <= target[3] and target[2] <= y <= target[4]
    else:
        return (x - target[1]) ** 2 + (y - target[2]) ** 2 <= target[3] ** 2


def main():
    m = int(sys.stdin.readline())
    targets = []
    for _ in range(m):
        entries = sys.stdin.readline().rstrip().split()
        coordinates = [int(x) for x in entries[1:]]
        targets.append([entries[0]] + coordinates)
    n = int(sys.stdin.readline())
    for _ in range(n):
        x, y = (int(z) for z in sys.stdin.readline().rstrip().split())
        target_count = 0
        for target in targets:
            if hit(target, x, y):
                target_count += 1
        print(target_count)


main()
