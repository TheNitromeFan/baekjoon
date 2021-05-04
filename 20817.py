import sys


def main():
    consonants = "bcdfghjklmnpqrstvwxz"
    line = sys.stdin.readline().rstrip()
    for c in consonants:
        while c * 3 in line:
            line = line.replace(c * 3, c * 2)
    sys.stdout.write(line)


main()
