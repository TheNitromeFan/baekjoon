import sys

ONES_TO_ROMAN = {0: "", 1: "I", 2: "II", 3: "III", 4: "IV", 5: "V", 6: "VI", 7: "VII", 8: "VIII", 9: "IX"}
TENS_TO_ROMAN = {0: "", 1: "X", 2: "XX", 3: "XXX", 4: "XL", 5: "L", 6: "LX", 7: "LXX", 8: "LXXX", 9: "XC"}
HUNDREDS_TO_ROMAN = {0: "", 1: "C", 2: "CC", 3: "CCC", 4: "CD", 5: "D", 6: "DC", 7: "DCC", 8: "DCCC", 9: "CM"}
THOUSANDS_TO_ROMAN = {0: "", 1: "M"}


def number_to_roman(number):
    if number > 1000:
        return "CONCORDIA CUM VERITATE"
    ret = ""
    ret = ONES_TO_ROMAN[number % 10] + ret
    number //= 10
    ret = TENS_TO_ROMAN[number % 10] + ret
    number //= 10
    ret = HUNDREDS_TO_ROMAN[number % 10] + ret
    number //= 10
    ret = THOUSANDS_TO_ROMAN[number % 10] + ret
    return ret


def roman_to_number(roman):
    if roman == "M":
        return 1000
    ret = 0
    for digit in range(9, -1, -1):
        m = len(HUNDREDS_TO_ROMAN[digit])
        if roman[:m] == HUNDREDS_TO_ROMAN[digit]:
            ret += digit * 100
            roman = roman[m:]
            break
    for digit in range(9, -1, -1):
        m = len(TENS_TO_ROMAN[digit])
        if roman[:m] == TENS_TO_ROMAN[digit]:
            ret += digit * 10
            roman = roman[m:]
            break
    for digit in range(9, -1, -1):
        m = len(ONES_TO_ROMAN[digit])
        if roman[:m] == ONES_TO_ROMAN[digit]:
            ret += digit
            break
    return ret


def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        a, b = sys.stdin.readline().rstrip()[:-1].split("+")
        sys.stdout.write(f"{a}+{b}={number_to_roman(roman_to_number(a) + roman_to_number(b))}\n\n")


main()
