import sys


def main():
    fibs = [0, 1]
    for _ in range(2, 491):
        fibs.append(fibs[-1] + fibs[-2])
    while True:
        n = int(sys.stdin.readline())
        if n == -1:
            break
        print("Hour {}: {} cow(s) affected".format(n, fibs[n]))


main()
