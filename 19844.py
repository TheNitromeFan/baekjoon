import sys


def main():
    sentence = sys.stdin.readline().rstrip()
    words = []
    word = ""
    for i, c in enumerate(sentence):
        if c in "- ":
            words.append(word)
            word = ""
        elif c == "'":
            if word in ["c", "j", "n", "m", "t", "s", "l", "d", "qu", "s"] and sentence[i + 1] in "aeiouh":
                words.append(word)
                word = ""
            else:
                word += c
        else:
            word += c
    if word:
        words.append(word)
    sys.stdout.write(str(len(words)))


main()
