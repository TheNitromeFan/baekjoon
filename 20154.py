import string
import sys


def main():
    strokes = [3, 2, 1, 2, 3, 3, 3, 3, 1, 1, 3, 1, 3, 3, 1, 2, 2, 2, 1, 2, 1, 1, 2, 2, 2, 1]
    stroke_counts = {x: v for (x, v) in zip(string.ascii_uppercase, strokes)}
    k = sys.stdin.readline().rstrip()
    if sum(stroke_counts[c] for c in k) % 2 == 1:
        print("I'm a winner!")
    else:
        print("You're the winner?")


main()
