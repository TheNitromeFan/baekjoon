import sys


keyboard = {"2": "abc", "3": "def", "4": "ghi", "5": "jkl", "6": "mno", "7": "pqrs", "8": "tuv", "9": "wxyz"}


def phone(word, number):
    if len(word) != len(number):
        return False
    for i in range(len(word)):
        if word[i] not in keyboard[number[i]]:
            return False
    return True


def main():
    n = int(sys.stdin.readline())
    words = []
    for _ in range(n):
        word = sys.stdin.readline().rstrip()
        words.append(word)
    number = sys.stdin.readline().rstrip()
    count = 0
    for word in words:
        if phone(word, number):
            count += 1
    print(count)


main()
