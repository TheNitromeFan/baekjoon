import sys


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        line = sys.stdin.readline().strip()
        try:
            n = int(line)
            if n < 0:
                print("invalid input")
            else:
                print(n)
        except ValueError:
            print("invalid input")


main()
