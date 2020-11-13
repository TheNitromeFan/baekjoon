import itertools


def main():
    n = int(input())
    ordered = input().split()
    words = input().split()
    words_dict = {word: i for i, word in enumerate(words)}
    ans = 0
    for first, second in itertools.combinations(ordered, 2):
        if words_dict[first] < words_dict[second]:
            ans += 1
    print("{}/{}".format(ans, n * (n - 1) // 2))


main()
