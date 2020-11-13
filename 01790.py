def length(n):
    ans = 0
    while n:
        ans += 1
        n //= 10
    return ans


def too_short(n, k):
    le = length(n)
    ans = 0
    for i in range(1, le):
        ans += 9 * 10 ** (i - 1) * i
    ans += (n - 10 ** (le - 1) + 1) * le
    return k > ans


def main():
    n, k = (int(x) for x in input().split())
    if too_short(n, k):
        print(-1)
        return
    digits = 1
    while k > 9 * 10 ** (digits - 1) * digits:
        k -= 9 * 10 ** (digits - 1) * digits
        digits += 1
    if digits == 1:
        print(k)
        return
    number = 10 ** (digits - 1) + (k-1) // digits
    print(str(number)[(k-1) % digits])


main()
