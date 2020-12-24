import sys


def main():
    k = int(sys.stdin.readline())
    for digits in range(1, 1100):
        for m in range(1, 10):
            x = (10 ** digits - 1) // 9 * m
            if x % k == 0:
                print(m, digits)
                return
    print("Impossible")


main()
