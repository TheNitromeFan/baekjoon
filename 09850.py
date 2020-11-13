import string


def shift(line, i):
    ret = ""
    for c in line:
        if c in string.ascii_uppercase:
            ret += string.ascii_uppercase[(string.ascii_uppercase.index(c) + i) % 26]
        else:
            ret += c
    return ret


def main():
    line = input()
    for i in range(1, 26):
        newline = shift(line, i)
        if "LIVE" in newline and "CHIPMUNK" in newline:
            print(newline)
            return


main()
