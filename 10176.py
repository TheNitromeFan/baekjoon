import string


def is_opposite(word):
    lowercase = string.ascii_lowercase
    letters = sorted(letter for letter in word.lower() if letter in lowercase)
    return all(lowercase.index(letters[i]) + lowercase.index(letters[-1-i]) == 25 for i in range(len(letters)))


def main():
    n = int(input())
    for _ in range(n):
        word = input()
        if is_opposite(word):
            print("Yes")
        else:
            print("No")


main()
