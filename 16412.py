def good_password(n):
    digits = []
    m = n
    while m:
        digits.append(m % 10)
        m //= 10
    return 0 not in digits and len(set(digits)) == 6 and all(n % digit == 0 for digit in digits)


def main():
    low, high = (int(x) for x in input().split())
    password_count = 0
    for c in range(low, high + 1):
        if good_password(c):
            password_count += 1
    print(password_count)


main()
