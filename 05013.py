import sys


def main():
    n = int(sys.stdin.readline())
    count = 0
    for _ in range(n):
        line = sys.stdin.readline()
        if "CD" not in line:
            count += 1
    print(count)


main()
