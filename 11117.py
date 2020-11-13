import sys
import string


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        box = sys.stdin.readline().rstrip()
        letter_counts = {x: box.count(x) for x in string.ascii_uppercase}
        w = int(sys.stdin.readline())
        for _ in range(w):
            word = sys.stdin.readline().rstrip()
            word_letter_counts = {x: word.count(x) for x in string.ascii_uppercase}
            if all(word_letter_counts[x] <= letter_counts[x] for x in string.ascii_uppercase):
                print("YES")
            else:
                print("NO")


main()
