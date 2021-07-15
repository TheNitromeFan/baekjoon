import sys


def has_palindrome(word):
    for length in range(2, 4):
        for idx in range(len(word) - length + 1):
            sub = word[idx:idx + length]
            if sub == sub[::-1]:
                return True
    return False


def main():
    n = int(sys.stdin.readline())
    words1, words2 = [], []
    for _ in range(n):
        word = sys.stdin.readline().rstrip()
        words1.append(word)
        words2.append(word.replace("j", "i").replace("b", "p").replace("d", "p"))
    print(sum(has_palindrome(word) for word in words1))
    print(sum(has_palindrome(word) for word in words2))


main()
