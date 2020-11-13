import itertools


def main():
    word = input()
    n = len(word)
    words = []
    for slice1, slice2 in itertools.combinations(range(1, n), 2):
        a, b, c = word[:slice1], word[slice1:slice2], word[slice2:]
        words.append(a[::-1] + b[::-1] + c[::-1])
    print(sorted(words)[0])


main()
