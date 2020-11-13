def make_palindrome(word):
    for i, _ in enumerate(word):
        new_word = word[:i] + word[i + 1:]
        if new_word == new_word[::-1]:
            return new_word
    return "not possible"


def main():
    while True:
        word = input()
        if word == "#":
            break
        print(make_palindrome(word))


main()
