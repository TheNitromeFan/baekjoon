import sys
import string


def main():
    n = int(sys.stdin.readline())
    word_pairs = []
    for _ in range(n):
        word_pairs.append(sys.stdin.readline().rstrip().split())
    for letter in string.ascii_lowercase:
        letter_count = 0
        for word1, word2 in word_pairs:
            letter_count += max(word1.count(letter), word2.count(letter))
        print(letter_count)


main()
