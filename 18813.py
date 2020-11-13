import sys
import string


def main():
    n, m = (int(x) for x in sys.stdin.readline().rstrip().split())
    word_count = 0
    for _ in range(n):
        word = sys.stdin.readline().rstrip()
        if all(letter in string.ascii_uppercase[:m] for letter in word) and len(word) == len(set(word)):
            word_count += 1
    print(word_count)


main()
