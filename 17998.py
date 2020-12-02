import sys


def main():
    alphabet = sys.stdin.readline().rstrip()
    word = sys.stdin.readline().rstrip()
    words = set()
    for i in range(len(word) + 1):
        for letter in alphabet:
            words.add(word[:i] + letter + word[i:])
    for i, _ in enumerate(word):
        words.add(word[:i] + word[i + 1:])
    for i, c in enumerate(word):
        for letter in alphabet:
            if c != letter:
                words.add(word[:i] + letter + word[i + 1:])
    sys.stdout.write("\n".join(sorted(words)))


main()
