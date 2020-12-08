import sys


def main():
    s = sys.stdin.readline().rstrip()
    substrings = set()
    for length in range(1, len(s) + 1):
        for i in range(len(s) + 1 - length):
            substrings.add(s[i:i + length])
    sys.stdout.write(str(len(substrings)))


main()
