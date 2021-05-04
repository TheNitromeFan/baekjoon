import sys


def main():
    words = sys.stdin.readline().rstrip().split()
    new_words = []
    for word in words:
        start, end = len(word) - len(word.lstrip("'")), len(word) - len(word.rstrip("'"))
        word = word.strip("'")
        if start:
            word = word[start:]
        if end:
            word = word[:-end]
        new_words.append(word)
    sys.stdout.write("".join(new_words))


main()
