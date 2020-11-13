import sys


def has_repeating_digit(n):
    return len(set(str(n))) < len(str(n))


def main():
    for line in sys.stdin:
        a, b = (int(x) for x in line.rstrip().split())
        ans = 0
        for i in range(a, b + 1):
            if not has_repeating_digit(i):
                ans += 1
        print(ans)


main()
