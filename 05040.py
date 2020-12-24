import sys
import string


def next_coordinates(row, col):
    col += 1
    if col > 5:
        row += 1
        col -= 5
    return row, col


def main():
    text = sys.stdin.readline().rstrip().replace(" ", "").upper()
    table = {}
    coordinates = {}
    row, col = 1, 1
    for c in text:
        if c not in table:
            table[c] = (row, col)
            coordinates[(row, col)] = c
            row, col = next_coordinates(row, col)
    for letter in string.ascii_uppercase:
        if letter != 'Q' and letter not in table:
            table[letter] = (row, col)
            coordinates[(row, col)] = letter
            row, col = next_coordinates(row, col)
    text = sys.stdin.readline().rstrip().replace(" ", "").upper()
    i = 0
    while i < len(text):
        if i == len(text) - 1 or text[i] == text[i + 1]:
            text = text[:i + 1] + 'X' + text[i + 1:]
        i += 2
    for i in range(0, len(text), 2):
        row1, col1 = table[text[i]]
        row2, col2 = table[text[i + 1]]
        if row1 == row2:
            col1 += 1
            if col1 > 5:
                col1 -= 5
            col2 += 1
            if col2 > 5:
                col2 -= 5
            sys.stdout.write(coordinates[(row1, col1)] + coordinates[(row2, col2)])
        elif col1 == col2:
            row1 += 1
            if row1 > 5:
                row1 -= 5
            row2 += 1
            if row2 > 5:
                row2 -= 5
            sys.stdout.write(coordinates[(row1, col1)] + coordinates[(row2, col2)])
        else:
            sys.stdout.write(coordinates[(row1, col2)] + coordinates[(row2, col1)])


main()
