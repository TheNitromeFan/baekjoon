import sys
import string


def main():
    k, n = (int(x) for x in sys.stdin.readline().split())
    words = {x: [] for x in string.ascii_lowercase}
    for _ in range(k):
        word = sys.stdin.readline().rstrip()
        words[word[0]].append(word)
    for val in words.values():
        val.sort()
    for _ in range(n):
        letter = sys.stdin.readline().rstrip()
        sys.stdout.write("{}\n".format(words[letter][0]))
        words[letter] = words[letter][1:] + [words[letter][0]]


main()
