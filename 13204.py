import sys


def process(n):
    for m in range(1, 66668):
        i = (2 * m * n + m) // 200000
        if 2 * m * n - m <= 200000 * i < 2 * m * n + m:
            sys.stdout.write("{}\n".format(m))
            return


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        n = int(sys.stdin.readline().rstrip().replace(".", ""))
        process(n)


main()
