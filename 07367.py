def forms_arithmetic_sequence(list1):
    return all(2 * list1[i] == list1[i - 1] + list1[i + 1] for i in range(1, len(list1) - 1))


def minimal_base(numbers):
    for b in range(2, 11):
        try:
            if forms_arithmetic_sequence([int(x, base=b) for x in numbers]):
                print("Minimum base = {}.".format(b))
                return
        except ValueError:
            continue
    print("No base <= 10 can be found.")


def main():
    while True:
        n = int(input())
        if n == 0:
            break
        numbers = input().split()
        minimal_base(numbers)


main()
