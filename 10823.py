import sys


def main():
    s = ""
    for line in sys.stdin:
        s += line.rstrip()
    print(sum(int(x) for x in s.split(",")))


main()
