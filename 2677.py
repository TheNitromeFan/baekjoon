import sys


EDSAC = "PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV"
WORD = "FD"


def main():
    p = int(sys.stdin.readline())
    for _ in range(p):
        number = sys.stdin.readline().rstrip()
        if number.rstrip("0") == "-1.":
            print("? 0 F")
            continue
        elif number[:3] == "-1.":
            print("INVALID VALUE")
            continue
        if float(number) < -1 or float(number) >= 1:
            print("INVALID VALUE")
            continue
        if number[0] == "-":
            sign = -1
            number = number[1:]
        else:
            sign = 1
        number += "0" * (18 - len(number))
        mantissa = int(number[2:])
        mantissa -= mantissa % (5 ** 16)
        if mantissa == 0:
            print("P 0 F")
            continue
        if sign > 0:
            binary = "0"
        else:
            binary = "1"
            mantissa = 10 ** 16 - mantissa
        for i in range(15, -1, -1):
            if mantissa >= 2 ** i * 5 ** 16:
                binary += "1"
                mantissa -= 2 ** i * 5 ** 16
            else:
                binary += "0"
        code = EDSAC[int(binary[:5], base=2)]
        decimal = int(binary[5:16], base=2)
        if binary[16] == "0":
            word = "F"
        else:
            word = "D"
        print("{} {} {}".format(code, decimal, word))


main()
