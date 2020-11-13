def cmp_2018(number):
    if any(x not in "2018" for x in number):
        return 0
    if any(x not in number for x in "2018"):
        return 1
    if number.count("2") == number.count("0") == number.count("1") == number.count("8"):
        return 8
    else:
        return 2


def main():
    n = input()
    print(cmp_2018(n))


main()
