import sys


display = {"0111111": 0, "0001010": 1, "1011101": 2, "1001111": 3, "1101010": 4,
           "1100111": 5, "1110111": 6, "0001011": 7, "1111111": 8, "1101011": 9}
code = {v: k for k, v in display.items()}


def c(numbers):
    summation = 0
    for number in numbers:
        a = 0
        for i in range(0, len(number), 3):
            a = a * 10 + display[bin(int(number[i:i + 3]))[2:].zfill(7)]
        summation += a
    ret = ""
    while summation:
        ret = str(int(code[summation % 10], base=2)).zfill(3) + ret
        summation //= 10
    return ret


def main():
    while True:
        line = sys.stdin.readline().rstrip()
        if line == "BYE":
            break
        numbers = line[:-1].split("+")
        print("{}{}".format(line, c(numbers)))


main()
