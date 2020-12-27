import sys


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        entries = sys.stdin.readline().split()
        w, n = entries[0], int(entries[1])
        sys.stdout.write(f"Shifting {w} by {n} positions gives us: {w[-n:] + w[:-n]}\n")


main()
