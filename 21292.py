import sys
import string


def number_to_french(n):
    if n <= 16:
        return ["zéro", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", "dix", "onze",
                "douze", "treize", "quatorze", "quinze", "seize"][n]
    elif n <= 19:
        return number_to_french(10) + "-" + number_to_french(n - 10)
    elif n <= 60 and n % 10 == 0:
        return ["", "", "vingt", "trente", "quarante", "cinquante", "soixante"][n // 10]
    elif n <= 61 and n % 10 == 1:
        return number_to_french(n - n % 10) + " et un"
    elif n <= 69:
        return number_to_french(n - n % 10) + "-" + number_to_french(n % 10)
    elif n == 70:
        return "soixante-dix"
    elif n == 71:
        return "soixante et onze"
    elif n <= 79:
        return "soixante-" + number_to_french(n - 60)
    elif n == 80:
        return "quatre-vingts"
    elif n == 81:
        return "quatre-vingt-un"
    elif n <= 99:
        return "quatre-vingt-" + number_to_french(n - 80)
    elif n == 100:
        return "cent"
    elif n <= 199:
        return "cent " + number_to_french(n - 100)
    elif n <= 900 and n % 100 == 0:
        return number_to_french(n // 100) + " cents"
    elif n <= 999:
        return number_to_french(n // 100) + " cent " + number_to_french(n % 100)
    elif n == 1000:
        return "mille"
    elif n == 1001:
        return "mille un"


def main2():
    for i in range(0, 1002, 7):
        print(number_to_french(i).replace("-", " "))


def main1():
    print(number_to_french(987).replace("-", " "))


def main3():
    print(chr(180))


def main():
    line = sys.stdin.readline().rstrip()
    letters = 0
    for c in line:
        # if c in string.ascii_letters + "ùûüÿàâæçéèêëïîôœ":
        if c in string.ascii_letters + "ÙÛÜŸÀÂÆÇÉÈÊËÏÎÔŒùûüÿàâæçéèêëïîôœ":
            letters += 1
    # print(letters)
    if letters % 7 <= 3:
        letters -= letters % 7
    else:
        letters += 7 - letters % 7
    print(number_to_french(letters).replace("-", " "))


main2()
# main1()
# main3()
main()
