import sys
import string


def distance(word1, word2):
    letters1 = {x: word1.count(x) for x in string.ascii_lowercase}
    letters2 = {x: word2.count(x) for x in string.ascii_lowercase}
    return sum(abs(letters2[x] - letters1[x]) for x in string.ascii_lowercase)


def main():
    n = int(sys.stdin.readline())
    for i in range(1, n + 1):
        word1 = sys.stdin.readline()
        word2 = sys.stdin.readline()
        print("Case #{}: {}".format(i, distance(word1, word2)))


main()
