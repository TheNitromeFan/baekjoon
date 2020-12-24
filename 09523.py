import sys


def val(morse_code):
    ret = 0
    for c in morse_code:
        if c == ".":
            ret += 1
        elif c == "-":
            ret += 5
        elif c == ":":
            ret += 2
        elif c == "=":
            ret += 10
    return ret


def main():
    n = int(sys.stdin.readline())
    morse = sys.stdin.readline().rstrip().split()
    for i in range(0, 2 * n + 2, 2):
        morse[i] = str(val(morse[i]))
    print(eval(" ".join(morse)))


main()
