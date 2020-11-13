from sys import stdin
from datetime import datetime


def valid_date(n):
    d, m, y = n % 100, n // 100 % 100, n // 100 // 100 % 400
    try:
        datetime(day=d, month=m, year=y)
        return True
    except ValueError:
        return False


def next_palindrome(number, digits):
    top = number // 10 ** (digits // 2)
    if digits % 2 == 0:
        cmp = top * 10 ** (digits // 2) + reverse(top)
        if cmp > number:
            return cmp, digits
        if top == 10 ** (digits // 2) - 1:
            return 10 ** digits + 1, digits + 1
        else:
            top += 1
            return top * 10 ** (digits // 2) + reverse(top), digits
    else:
        cmp = top * 10 ** (digits // 2) + reverse(top // 10)
        if cmp > number:
            return cmp, digits
        if top == 10 ** (digits // 2 + 1) - 1:
            return 10 ** digits + 1, digits + 1
        else:
            top += 1
            return top * 10 ** (digits // 2) + reverse(top // 10), digits


def reverse(number):
    ret = 0
    while number:
        ret = ret * 10 + number % 10
        number //= 10
    return ret


def main():
    n = int(stdin.readline())
    for _ in range(n):
        d, m, y = (int(x) for x in stdin.readline().split('/'))
        date = 100 * 100 * y + 100 * m + d
        ans, digits = next_palindrome(date, len(str(date)))
        while not valid_date(ans):
            ans, digits = next_palindrome(ans, digits)
        print("{}/{}/{}".format(str(ans % 100).zfill(2), str(ans // 100 % 100).zfill(2), ans // 100 // 100))


main()
