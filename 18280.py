import sys
import string


OPERATORS = "+-*/"


def parse(equation):
    idx = 0
    number1 = ""
    while idx < len(equation) and equation[idx] in string.digits:
        number1 += equation[idx]
        idx += 1
    if not number1 or number1[0] == "0" or int(number1) > 10 ** 9:
        return False
    if idx == len(equation) or equation[idx] not in OPERATORS:
        return False
    operator = equation[idx]
    idx += 1
    number2 = ""
    while idx < len(equation) and equation[idx] in string.digits:
        number2 += equation[idx]
        idx += 1
    if not number2 or number2[0] == "0" or int(number2) > 10 ** 9:
        return False
    if idx == len(equation) or equation[idx] != "=":
        return False
    idx += 1
    number3 = ""
    while idx < len(equation) and equation[idx] in string.digits:
        number3 += equation[idx]
        idx += 1
    if not number3 or number3[0] == "0" or int(number3) > 10 ** 9:
        return False
    if idx < len(equation):
        return False
    return int(number1), operator, int(number2), int(number3)


def valid(number1, operator, number2, number3):
    return (operator == "+" and number1 + number2 == number3) or (operator == "-" and number1 - number2 == number3)\
        or (operator == "*" and number1 * number2 == number3) or (operator == "/" and number1 == number2 * number3)


def check(equation):
    res = parse(equation)
    if not res:
        return "Izraz nije ispravno formatiran"
    number1, operator, number2, number3 = res
    if valid(number1, operator, number2, number3):
        return "Tocno"
    for idx1 in range(len(equation)):
        for idx2 in range(idx1):
            for c1 in string.digits + OPERATORS + "=":
                for c2 in string.digits + OPERATORS + "=":
                    equation1 = equation[:idx2] + c2 + equation[idx2 + 1:idx1] + c1 + equation[idx1 + 1:]
                    res1 = parse(equation1)
                    if not res1:
                        continue
                    number4, operator1, number5, number6 = res1
                    if valid(number4, operator1, number5, number6):
                        return f"Netocno, umjesto {equation} mogli ste ispisati {equation1}"
    return "Potpuno netocno"


def main():
    equation = sys.stdin.readline().rstrip()
    sys.stdout.write(check(equation))


main()
