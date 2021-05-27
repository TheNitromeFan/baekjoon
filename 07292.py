import sys
import string


points_to_letters = {10: 'QZ', 8: 'JX', 5: 'K', 4: 'FHVWY', 3: 'BCMP', 2: 'DG', 1: 'AEILNORSTU'}
letters_to_points = {}
for key, val in points_to_letters.items():
    for letter in val:
        letters_to_points[letter] = key
word_multiplier = {(1, 'A'): 3, (1, 'H'): 3, (1, 'O'): 3, (2, 'B'): 2, (2, 'N'): 2, (3, 'C'): 2, (3, 'M'): 2,
                   (4, 'D'): 2, (4, 'L'): 2, (5, 'E'): 2, (5, 'K'): 2, (8, 'A'): 3, (8, 'H'): 2, (8, 'O'): 3}
letter_multiplier = {(1, 'D'): 2, (1, 'L'): 2, (2, 'F'): 3, (2, 'J'): 3, (3, 'G'): 2, (3, 'I'): 2, (4, 'A'): 2,
                     (4, 'H'): 2, (4, 'O'): 2, (6, 'B'): 3, (6, 'F'): 3, (6, 'J'): 3, (6, 'N'): 3, (7, 'C'): 2,
                     (7, 'G'): 2, (7, 'I'): 2, (7, 'M'): 2, (8, 'D'): 2, (8, 'L'): 2}
tmp = list(word_multiplier.keys())
for number, letter in tmp:
    word_multiplier[(16 - number, letter)] = word_multiplier[(number, letter)]
tmp = list(letter_multiplier.keys())
for number, letter in tmp:
    letter_multiplier[(16 - number, letter)] = letter_multiplier[(number, letter)]
while True:
    entries = sys.stdin.readline().rstrip().split()
    if entries == ['#']:
        break
    coordinate, word = entries
    if coordinate[0] in string.ascii_uppercase:
        vertical = True
        row, column = int(coordinate[1:]), coordinate[0]
    else:
        vertical = False
        row, column = int(coordinate[:-1]), coordinate[-1]
    score = 0
    word_bonus = 1
    for ind, letter in enumerate(word):
        letter_score = letters_to_points[letter]
        if (row, column) in word_multiplier:
            word_bonus *= word_multiplier[(row, column)]
        elif (row, column) in letter_multiplier:
            letter_score *= letter_multiplier[(row, column)]
        score += letter_score
        if vertical:
            row += 1
        else:
            column = chr(ord(column) + 1)
    score *= word_bonus
    print(coordinate, word, score)
