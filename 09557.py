import string


def find_english(words):
    for i, word in enumerate(words):
        if word[0] in string.ascii_lowercase:
            return i
    return -1


def main():
    t = int(input())
    for _ in range(t):
        input()
        words = input().split()
        ind = find_english(words)
        if ind == -1:
            print(" ".join(words))
        else:
            print(" ".join(words[ind+1:] + [words[ind]] + words[:ind]))


main()
