LETTERS = "ABCDEFGHIJ"


def main():
    n = int(input())
    words = []
    frequencies = {letter: 0 for letter in LETTERS}
    forbidden = set()
    for _ in range(n):
        word = input()
        forbidden.add(word[0])
        words.append(word)
        for ind, val in enumerate(word[::-1]):
            frequencies[val] += 10 ** ind
    sorted_letters = sorted(LETTERS, key=lambda x: frequencies[x], reverse=True)
    i = -2
    while sorted_letters[-1] in forbidden:
        sorted_letters[-1], sorted_letters[i] = sorted_letters[i], sorted_letters[-1]
        i -= 1
    keys = {k: 9-i for i, k in enumerate(sorted_letters)}
    numbers = []
    for word in words:
        for key in LETTERS:
            word = word.replace(key, str(keys[key]))
        numbers.append(word)
    print(sum(int(number) for number in numbers))


main()
