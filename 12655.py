import sys
import itertools


def word_count(words, patterns):
    ret = 0
    for word in words:
        flag = True
        for i, letter in enumerate(word):
            if letter not in patterns[i]:
                flag = False
                break
        if flag:
            ret += 1
    return ret


def main():
    l, d, n = (int(x) for x in sys.stdin.readline().split())
    words = []
    for _ in range(d):
        words.append(sys.stdin.readline().rstrip())
    for a0 in range(1, n + 1):
        pattern = sys.stdin.readline().rstrip()
        idx = 0
        combinations = []
        while idx < len(pattern):
            if pattern[idx] == "(":
                letters = ""
                idx += 1
                while idx < len(pattern) and pattern[idx] != ")":
                    letters += pattern[idx]
                    idx += 1
                combinations.append(letters)
            else:
                combinations.append(pattern[idx])
            idx += 1
        sys.stdout.write("Case #{}: {}\n".format(a0, word_count(words, combinations)))


main()
