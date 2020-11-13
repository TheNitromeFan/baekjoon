import sys


def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        entries = sys.stdin.readline().rstrip().split()
        bases = []
        for b in range(2, 17):
            try:
                p, q, r = (int(x, base=b) for x in entries)
                if p * q == r:
                    bases.append(b)
            except ValueError:
                continue
        if bases:
            print(bases[0])
        else:
            print(0)


main()
