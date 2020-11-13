import sys


def main():
    t = int(sys.stdin.readline())
    for case in range(1, t + 1):
        n = int(sys.stdin.readline())
        prev = sys.stdin.readline()
        price = 0
        for _ in range(1, n):
            cur = sys.stdin.readline()
            if prev < cur:
                prev = cur
            else:
                price += 1
        print("Case #{}: {}".format(case, price))


main()
