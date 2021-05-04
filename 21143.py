import sys


def main():
    s = sys.stdin.readline().rstrip()
    print(int(len(s) == len(set(s))))


main()
