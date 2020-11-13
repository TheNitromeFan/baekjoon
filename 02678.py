import sys


EDSAC = "PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV"
WORD = "FD"


def main():
    p = int(sys.stdin.readline())
    for _ in range(p):
        entries = sys.stdin.readline().strip().split()
        c, d, s = entries[0], int(entries[1]), entries[2]
        binary = bin(EDSAC.index(c))[2:].zfill(5) + bin(d)[2:].zfill(11) + bin(WORD.index(s))[2:].zfill(1)
        sign = 1
        if binary[0] == "1":
            sign = -1
        mantissa = int(binary[1:], base=2) * 5 ** 16
        if mantissa != 0 and sign == -1:
            print_string = "-0.{}".format(str(10 ** 16 - mantissa).zfill(16)).rstrip("0")
        elif mantissa != 0:
            print_string = "0.{}".format(str(mantissa).zfill(16)).rstrip("0")
        elif sign == -1:
            print_string = "-1.0"
        else:
            print_string = "0.0"
        print(print_string)


main()
