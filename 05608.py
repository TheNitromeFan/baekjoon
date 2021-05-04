import sys


def main():
    n = int(sys.stdin.readline())
    replace_table = {}
    for _ in range(n):
        before, after = sys.stdin.readline().rstrip().split()
        replace_table[before] = after
    m = int(sys.stdin.readline())
    for _ in range(m):
        letter = sys.stdin.readline().rstrip()
        if letter in replace_table:
            sys.stdout.write(replace_table[letter])
        else:
            sys.stdout.write(letter)


main()
