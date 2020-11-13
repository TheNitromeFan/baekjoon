def prime(number):
    if number in [0, 1]:
        return False
    for p in range(2, int(number ** 0.5) + 1):
        if number % p == 0:
            return False
    return True


def main():
    n, d = input().split()
    number1, number2 = int(n), int(d + n)
    if prime(number1) and prime(number2):
        print("Yes")
    else:
        print("No")


main()
