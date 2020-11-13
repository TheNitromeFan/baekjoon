import sys
import string


def name(word):
    if len(word) == 1:
        return word in string.ascii_uppercase
    return word[0] in string.ascii_uppercase and all(x in string.ascii_lowercase for x in word[1:-1]) \
        and word[-1] in string.ascii_lowercase + ".?!"


def main():
    sys.stdin.readline()
    words = sys.stdin.readline().rstrip().split()
    name_count = 0
    for word in words:
        if name(word):
            name_count += 1
        if word[-1] in ".?!":
            print(name_count)
            name_count = 0
    assert name_count == 0


main()
