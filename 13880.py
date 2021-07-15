import sys


def main():
    p = int(sys.stdin.readline())
    for _ in range(p):
        k, n = (int(x) for x in sys.stdin.readline().split())
        seq = bin(n)[2:]
        n, d = 0, 1
        for c in seq:
            if c == "1":
                n += d
            else:
                d += n
        sys.stdout.write(f"{k} {n}/{d}\n")


main()
