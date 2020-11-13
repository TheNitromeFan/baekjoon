def length(n):
    ans = 0
    while n:
        ans += 1
        n //= 10
    return ans


def main():
    n = int(input())
    le = length(n)
    ans = 0
    for i in range(1, le):
        ans += 9 * 10 ** (i - 1) * i
    ans += (n - 10 ** (le - 1) + 1) * le
    print(ans)


main()
