import sys


def main():
    colors = "RGBY"
    start = sys.stdin.readline().rstrip()
    target = sys.stdin.readline().rstrip()
    print(sum(abs(start.count(color) - target.count(color)) for color in colors) // 2)


main()
