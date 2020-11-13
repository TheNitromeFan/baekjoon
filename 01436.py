from string import digits
from itertools import product


def main():
    n = int(input())
    number_count, length = 0, 3
    while True:
        for number in product(digits, repeat=length):
            if number[0] == '0':
                continue
            number = "".join(number)
            if '666' in number:
                number_count += 1
                if number_count == n:
                    print(number)
                    return
        length += 1


main()
