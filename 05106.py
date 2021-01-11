import sys
import string


def main():
    while True:
        n = int(sys.stdin.readline())
        if n == 0:
            break
        letters_used = {letter: 0 for letter in string.ascii_lowercase}
        words = []
        for _ in range(n):
            word = sys.stdin.readline().rstrip()
            words.append(word)
            for letter in string.ascii_lowercase:
                letters_used[letter] = max(letters_used[letter], word.count(letter))
        board = "".join(key * val for key, val in letters_used.items())
        ans = board
        for i, letter in enumerate(board):
            if all(letter in word for word in words):
                board = board[:i] + board[i + 1:]
                ans = board[:4] + letter + board[4:]
                break
        sys.stdout.write(" ".join(letter.upper() for letter in ans) + "\n")


main()
