import sys


def attack(board):
    for i in range(1, 10):
        if len(set(board[(i, j)] for j in range(1, 10))) < 9:
            return False
    for j in range(1, 10):
        if len(set(board[(i, j)] for i in range(1, 10))) < 9:
            return False
    for x in range(1, 10, 3):
        for y in range(1, 10, 3):
            if len(set(board[(i, j)] for i in range(x, x + 3) for j in range(y, y + 3))) < 9:
                return False
    return True


def main():
    g = int(sys.stdin.readline())
    for _ in range(g):
        board = {}
        for i in range(1, 10):
            entries = sys.stdin.readline().rstrip().split()
            for j in range(1, 10):
                board[(i, j)] = entries[j - 1]
        # print(board)
        if attack(board):
            sys.stdout.write("all 3\n")
        else:
            sys.stdout.write("not\n")


main()
