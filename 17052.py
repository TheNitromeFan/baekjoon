import string


def valid(card):
    digits = [int(x) for x in card]
    doubled = []
    for i, digit in enumerate(digits[::-1][1:]):
        if i % 2 == 0:
            number = digit * 2
            if number > 9:
                number -= 9
        else:
            number = digit
        doubled.append(number)
    return sum(doubled) * 9 % 10 == digits[-1]


def main():
    input()
    card = input()
    ind = card.index('x')
    for digit in string.digits:
        candidate = card[:ind] + digit + card[ind+1:]
        if valid(candidate):
            print(digit)
            return


main()
