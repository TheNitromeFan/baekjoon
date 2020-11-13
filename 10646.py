def number_to_digits(number):
    digits = []
    while number:
        digits.append(number % 10)
        number //= 10
    return digits[::-1]


def digits_to_number(digits):
    res = 0
    for digit in digits:
        res = res * 10 + digit
    return res


def make_handsome(digits, position_to_change):
    answer = []
    d = digits.copy()
    p = position_to_change
    if d[p] > 0:
        d[p] -= 1
        while p + 1 < len(d):
            d[p + 1] = 9 - d[p] % 2
            p += 1
        answer.append(digits_to_number(d))
    d = digits.copy()
    p = position_to_change
    if d[p] < 9:
        d[p] += 1
        while p + 1 < len(d):
            d[p + 1] = 1 - d[p] % 2
            p += 1
        answer.append(digits_to_number(d))
    return answer


def nearest_handsome(n):
    digits = number_to_digits(n)
    for ind, val in enumerate(digits):
        if abs(digits[ind+1] - val) % 2 == 0:
            return make_handsome(digits, ind+1)
    return [n]


def main():
    n = int(input())
    x = nearest_handsome(n)
    if len(x) == 2:
        a, b = x
        if abs(n - a) < abs(b - n):
            print(a)
        elif abs(n - a) > abs(b - n):
            print(b)
        else:
            print("{} {}".format(a, b))
    else:
        print(x[0])


main()
