def persistent(n):
    if n < 10:
        return 10 + n
    single_digit_factors = []
    for i in range(9, 1, -1):
        while n % i == 0:
            single_digit_factors.append(i)
            n //= i
    if n > 1:
        return "There is no such number."
    answer = 0
    for digit in reversed(single_digit_factors):
        answer = answer * 10 + digit
    return answer


def main():
    while True:
        n = int(input())
        if n == -1:
            break
        print(persistent(n))


main()
