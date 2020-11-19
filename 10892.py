import sys


def main():
    n = int(sys.stdin.readline())
    points = {}
    for i in range(1, 3 * n + 1):
        x, y = (int(z) for z in sys.stdin.readline().split())
        points[i] = (x, y)
    numbers = list(range(1, 3 * n + 1))
    numbers.sort(key=lambda z: points[z])
    for i in range(0, 3 * n, 3):
        sys.stdout.write("{} {} {}\n".format(numbers[i], numbers[i + 1], numbers[i + 2]))


main()
