import sys
import string


def main():
    code = sys.stdin.readline().rstrip()
    for letter in string.ascii_lowercase:
        code = code.replace(letter, ' ')
    numbers = {int(x) for x in code.split()}
    print(len(numbers))


main()
