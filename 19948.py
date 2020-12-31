import sys
import string


def title(poem, spacebar, alphabet):
    previous = ""
    for letter in poem:
        if letter == previous:
            continue
        if letter == " ":
            if spacebar == 0:
                return -1
            spacebar -= 1
        else:
            if alphabet[letter.upper()] == 0:
                return -1
            alphabet[letter.upper()] -= 1
        previous = letter
    ret = "".join(word[0] for word in poem.upper().split())
    previous = ""
    for letter in ret:
        if letter == previous:
            continue
        if alphabet[letter] == 0:
            return -1
        alphabet[letter] -= 1
        previous = letter
    return ret


def main():
    poem = sys.stdin.readline().rstrip()
    spacebar = int(sys.stdin.readline())
    keyboard = [int(x) for x in sys.stdin.readline().split()]
    alphabet = {letter: num for letter, num in zip(string.ascii_uppercase, keyboard)}
    print(title(poem, spacebar, alphabet))


main()
