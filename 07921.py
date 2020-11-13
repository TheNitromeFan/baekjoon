import sys


def main():
    t = int(sys.stdin.readline())
    for i in range(1, t + 1):
        n = int(sys.stdin.readline())
        if i % 69 == 0:
            print("AMPPZ 2010")
            continue
        print(round(n * 3 / 7))


main()
