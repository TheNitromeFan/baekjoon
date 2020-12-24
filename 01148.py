import sys
import string


def can_form_word(word, letters, letter):
    if letter not in word:
        return False
    for tile in string.ascii_uppercase:
        if word.count(tile) > letters.count(tile):
            return False
    return True


def main():
    words = []
    while True:
        word = sys.stdin.readline().rstrip()
        if word == "-":
            break
        words.append(word)
    while True:
        grid = sys.stdin.readline().rstrip()
        if grid == "#":
            break
        minimum_word_letters, maximum_word_letters = [], []
        minimum_attained, maximum_attained = len(words) + 1, -1
        for letter in sorted(set(grid)):
            word_count = 0
            for word in words:
                if can_form_word(word, grid, letter):
                    word_count += 1
            if word_count < minimum_attained:
                minimum_word_letters = [letter]
                minimum_attained = word_count
            elif word_count == minimum_attained:
                minimum_word_letters.append(letter)
            if word_count > maximum_attained:
                maximum_word_letters = [letter]
                maximum_attained = word_count
            elif word_count == maximum_attained:
                maximum_word_letters.append(letter)
        print("".join(minimum_word_letters), minimum_attained, "".join(maximum_word_letters), maximum_attained)


main()
