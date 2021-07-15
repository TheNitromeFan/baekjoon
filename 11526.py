import sys


def main():
    p = int(sys.stdin.readline())
    for _ in range(p):
        k, fraction = sys.stdin.readline().split()
        k = int(k)
        n, d = (int(x) for x in fraction.split("/"))
        b = ""
        while (n, d) != (0, 1):
            if n >= d:
                b += "1"
                n -= d
            else:
                b += "0"
                d -= n
        sys.stdout.write(f"{k} {int(b[::-1], base=2)}\n")


main()
