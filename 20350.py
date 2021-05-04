import sys
import string


def main():
    s = sys.stdin.readline().rstrip()
    s = s[4:] + s[:4]
    for num, char in enumerate(string.ascii_uppercase, start=10):
        s = s.replace(char, str(num))
    if int(s) % 97 == 1:
        sys.stdout.write("correct")
    else:
        sys.stdout.write("incorrect")


main()
