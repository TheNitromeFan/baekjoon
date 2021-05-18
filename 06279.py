import sys


def main():
    a006534 = [1, 1, 1, 1, 4, 6, 19, 43, 120, 307, 866, 2336, 6588, 18373, 52119, 147700, 422016]
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        n = int(sys.stdin.readline())
        print(f"Case #{a0}: {a006534[n]}")


main()
