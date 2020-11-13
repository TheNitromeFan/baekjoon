import sys


def main():
    while True:
        n = int(sys.stdin.readline())
        if n == 0:
            break
        ranges = sys.stdin.readline().rstrip().split(",")
        printed = [False] * (n + 1)
        for r in ranges:
            if "-" in r:
                low, high = (int(x) for x in r.split("-"))
                for x in range(low, min(high + 1, n + 1)):
                    printed[x] = True
            elif int(r) <= n:
                printed[int(r)] = True
        print(sum(printed))


main()
