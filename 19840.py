import sys

MOD = 10 ** 9 + 7


def main():
    n = int(sys.stdin.readline())
    numbers = [int(ai) for ai in sys.stdin.readline().split()]
    x = sum(numbers)
    ans = 0
    for ai in numbers:
        ans += x * 10 ** len(str(ai)) + ai * n
        ans -= ai * (10 ** len(str(ai)) + 1)
        ans %= MOD
    print(ans)


main()
