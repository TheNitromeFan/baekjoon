import sys


def main():
    a, b = (int(z) for z in sys.stdin.readline().split())
    if a > b:
        a, b = b, a
    x, y = (int(z) for z in sys.stdin.readline().split())
    if not 0 <= y < abs(x):
        sys.stdout.write("Unknwon Number")
        return
    c = a - a % x + y
    for num in [c - 2 * abs(x), c - abs(x), c, c + abs(x), c + 2 * abs(x)]:
        if num - abs(x) < a <= num <= b < num + abs(x):
            sys.stdout.write("{}".format(num))
            return
    else:
        sys.stdout.write("Unknwon Number")


main()
