from string import ascii_uppercase


def main():
    words = []
    frequencies = {x: 0 for x in ascii_uppercase}
    for _ in range(int(input())):
        word = input()
        for ind, val in enumerate(word[::-1]):
            frequencies[val] += 10 ** ind
        words.append(word)
    change = sorted(ascii_uppercase, key=lambda x: frequencies[x], reverse=True)
    assignment = {change[i]: str(9-i) for i in range(10)}
    converted = []
    for word in words:
        for character in word:
            if not '0' <= character <= '9':
                word = word.replace(character, assignment[character])
        converted.append(word)
    print(sum(int(x) for x in converted))


main()
