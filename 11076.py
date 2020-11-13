ones = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
teens = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
tens = [None, None, "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]


def number_to_word(s):
    if not s:
        return "zero"
    n = int(s)
    if n < 10:
        return ones[n]
    elif n < 20:
        return teens[n - 10]
    elif n < 100:
        if n % 10 == 0:
            return tens[n // 10]
        else:
            return tens[n // 10] + "-" + number_to_word(n % 10)
    elif n < 10 ** 3:
        if n % 100 == 0:
            return ones[n // 100] + " hundred"
        else:
            return ones[n // 100] + " hundred and " + number_to_word(n % 100)
    elif n < 10 ** 6:
        if n % (10 ** 3) == 0:
            return number_to_word(n // (10 ** 3)) + " thousand"
        elif n % (10 ** 3) < 100:
            return number_to_word(n // (10 ** 3)) + " thousand and " + number_to_word(n % (10 ** 3))
        else:
            return number_to_word(n // (10 ** 3)) + " thousand " + number_to_word(n % (10 ** 3))
    elif n < 10 ** 9:
        if n % (10 ** 6) == 0:
            return number_to_word(n // (10 ** 6)) + " million"
        elif n % (10 ** 6) < 100:
            return number_to_word(n // (10 ** 6)) + " million and " + number_to_word(n % (10 ** 6))
        else:
            return number_to_word(n // (10 ** 6)) + " million " + number_to_word(n % (10 ** 6))
    else:
        if n % (10 ** 9) == 0:
            return number_to_word(n // (10 ** 9)) + " billion"
        elif n % (10 ** 9) < 100:
            return number_to_word(n // (10 ** 9)) + " billion and " + number_to_word(n % (10 ** 9))
        else:
            return number_to_word(n // (10 ** 9)) + " billion " + number_to_word(n % (10 ** 9))


def main():
    money = input()
    if "." not in money:
        money += ".00"
    dollar_amount, cent_amount = money[:-3], money[-2:]
    if dollar_amount[0] == "-":
        dollar_amount = dollar_amount[2:]
        debit = True
    else:
        dollar_amount = dollar_amount[1:]
        debit = False
    dollars, cents = number_to_word(dollar_amount), number_to_word(cent_amount)
    dollar_word, cent_word = "dollars", "cents"
    if dollars == "one":
        dollar_word = "dollar"
    if cents == "one":
        cent_word = "cent"
    if dollars == "zero" and cents == "zero":
        balance = ""
    elif debit:
        balance = " in debit"
    else:
        balance = " in credit"
    print(dollars + " " + dollar_word + " and " + cents + " " + cent_word + balance)


main()
