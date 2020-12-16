import sys
import string


def decimal_to_bijective_base_26(n):
    ret = ""
    while n:
        n -= 1
        ret = string.ascii_uppercase[n % 26] + ret
        n //= 26
    return ret


def main():
    while True:
        rncm = sys.stdin.readline().rstrip()
        r, c = rncm.index("R"), rncm.index("C")
        row, col = int(rncm[r + 1:c]), int(rncm[c + 1:])
        if row == col == 0:
            break
        sys.stdout.write("{}{}\n".format(decimal_to_bijective_base_26(col), row))


main()
