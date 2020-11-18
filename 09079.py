import sys
import itertools


def valid_flip(board, flips):
    for flip in flips:
        if 1 <= flip <= 3:
            for i in range(3):
                board[3 * (flip - 1) + i] = not board[3 * (flip - 1) + i]
        elif 4 <= flip <= 6:
            for i in range(3):
                board[3 * i + flip - 4] = not board[3 * i + flip - 4]
        elif flip == 7:
            for i in range(3):
                board[3 * i + i] = not board[3 * i + i]
        else:
            for i in range(3):
                board[3 * i + 2 - i] = not board[3 * i + 2 - i]
    return all(board) or not any(board)


def min_flips(board):
    for length in range(0, 9):
        for flips in itertools.combinations(range(1, 9), length):
            if valid_flip(board[::], flips):
                return length
    return -1


def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        board = []
        for _ in range(3):
            board += [x == "H" for x in sys.stdin.readline().rstrip().split()]
        sys.stdout.write("{}\n".format(min_flips(board)))


main()
