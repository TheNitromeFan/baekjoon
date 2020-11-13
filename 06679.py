def decimal_to_base(number, base):
    result = []
    while number:
        result.append(number % base)
        number //= base
    return result


def main():
    for n in range(2992, 10000):
        if sum(decimal_to_base(n, 10)) == sum(decimal_to_base(n, 12)) == sum(decimal_to_base(n, 16)):
            print(n)


main()
