import sys


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        n = int(sys.stdin.readline())
        print(n)
        m = n
        while True:
            m = m // 10 - m % 10
            if m > 0:
                print(m)
            else:
                break
        if m % 11 == 0:
            print("The number {} is divisible by 11.".format(n))
        else:
            print("The number {} is not divisible by 11.".format(n))
        print()


main()
