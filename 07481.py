import sys


def print_bills():
    a, b, s = (int(x) for x in sys.stdin.readline().split())
    swap = False
    if a > b:
        a, b = b, a
        swap = True
    for x in range(b):
        if a * x <= s and a * x % b == s % b:
            y = (s - a * x) // b
            if swap:
                x, y = y, x
            print("{} {}".format(x, y))
            return
    print("Impossible")


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        print_bills()


main()
