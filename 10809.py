from string import ascii_lowercase


def letter_places(word):
    letters = {c: -1 for c in ascii_lowercase}
    for letter in word:
        letters[letter] = word.find(letter)
    return letters


places = letter_places(input())
print(" ".join(str(places[x]) for x in ascii_lowercase))
