import sys


def main():
    sys.stdin.readline()
    a = {int(x) for x in sys.stdin.readline().split()}
    b = {int(x) for x in sys.stdin.readline().split()}
    c = a & b
    print("\n".join(str(x) for x in sorted(c)))


main()
