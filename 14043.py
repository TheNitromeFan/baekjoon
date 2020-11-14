import sys
import string


def main():
    word1 = sys.stdin.readline().rstrip()
    word2 = sys.stdin.readline().rstrip()
    if all(word2.count(x) <= word1.count(x) for x in string.ascii_lowercase):
        print("A")
    else:
        print("N")


main()
