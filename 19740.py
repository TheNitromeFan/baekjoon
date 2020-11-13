import sys


def main():
    n = int(sys.stdin.readline())
    tests = []
    for _ in range(n):
        s = sys.stdin.readline().rstrip()
        m, length = int(s), len(s)
        tests.append(m)
    tests.append(10 ** (length - 1))
    print(max(tests))
    print(10 ** length - 1)


main()
