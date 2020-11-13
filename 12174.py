import sys


def translate_byte(byte):
    code = 0
    for i in range(8):
        code *= 2
        code += (byte[i] == 'I')
    return chr(code)


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        b = int(sys.stdin.readline())
        line = sys.stdin.readline().rstrip()
        s = ""
        for i in range(0, 8 * b, 8):
            s += translate_byte(line[i: i + 8])
        print("Case #{}: {}".format(a0, s))


main()
