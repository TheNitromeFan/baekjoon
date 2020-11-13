import sys


def main():
    lengths = {"char": 2, "int": 8, "long_long": 16}
    code = sys.stdin.readline().rstrip()
    n = int(sys.stdin.readline())
    types = sys.stdin.readline().rstrip().split()
    pos = 0
    for type in types:
        print(int(code[pos : pos + lengths[type]], base=16), end=" ")
        pos += lengths[type]


main()
