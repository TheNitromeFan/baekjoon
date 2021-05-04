import sys


def main():
    b = int(sys.stdin.readline())
    x = int(sys.stdin.readline())
    alpha = ""
    while x:
        if x % b:
            alpha = str(x % b) + alpha
            x //= b
        else:
            alpha = str(b) + alpha
            x -= b
            x //= b
    print(alpha)


main()
