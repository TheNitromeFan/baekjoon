from math import gcd


def main():
    for _ in range(int(input())):
        number = input()
        if '(' in number:
            i, j = number.find('('), number.find(')')
            number = number.replace('(', '').replace(')', '')
            if i == 2:
                numerator = int(number[2:])
            else:
                numerator = int(number[2:]) - int(number[2:i])
            denominator = 10 ** (i-2) * (10 ** (j-i-1) - 1)
        else:
            numerator = int(number[2:])
            denominator = 10 ** (len(number)-2)
        g = gcd(numerator, denominator)
        print("{}/{}".format(numerator // g, denominator // g))


main()
