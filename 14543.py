import sys


def truncate(x):
    return int(x * 10 ** 6) / 10 ** 6


def main():
    n = int(sys.stdin.readline())
    for a0 in range(1, n + 1):
        entries = sys.stdin.readline().split()
        a, b, c = int(entries[0][:-1]), int(entries[2]), int(entries[4])
        if a:
            ans = f"x = {truncate((c - b) / a):.6f}"
        elif b == c:
            ans = "More than one solution."
        else:
            ans = "No solution."
        print(f"Equation {a0}\n{ans}\n")


main()
