import string


LETTERS = string.ascii_uppercase[:15]


def distance(coordinates1, coordinates2):
    return abs(coordinates1[0] - coordinates2[0]) + abs(coordinates1[1] - coordinates2[1])


def main():
    starting_board = ["ABCD", "EFGH", "IJKL", "MNO."]
    starting_coordinates = {}
    for i in range(4):
        for j in range(4):
            if starting_board[i][j] in LETTERS:
                starting_coordinates[starting_board[i][j]] = (i, j)
    ending_board = [input() for _ in range(4)]
    ending_coordinates = {}
    for i in range(4):
        for j in range(4):
            if ending_board[i][j] in LETTERS:
                ending_coordinates[ending_board[i][j]] = (i, j)
    print(sum(distance(starting_coordinates[x], ending_coordinates[x]) for x in LETTERS))


main()
