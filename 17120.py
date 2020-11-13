import sys


def main():
    for line in sys.stdin:
        if ":cat:" in line.lower():
            print("YES")
        else:
            print("NO")


main()
