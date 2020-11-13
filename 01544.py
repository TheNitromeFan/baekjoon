def all_cycles(word):
    return {word[i:] + word[:i]  for i, _ in enumerate(word)}


def already_counted(words, new_word):
    for word in words:
        if new_word in words[word]:
            return True
    return False


def main():
    n = int(input())
    words = {}
    for _ in range(n):
        new_word = input()
        if not already_counted(words, new_word):
            words[new_word] = all_cycles(new_word)
    print(len(words))


main()
