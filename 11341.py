vowels = "aeiouy"


def first_vowel_index(word):
    ans = 0
    while ans < len(word):
        if word[ans] in vowels:
            return ans
        ans += 1
    return ans


def translate(word):
    ind = first_vowel_index(word)
    if ind:
        return word[ind:] + word[:ind] + "ay"
    else:
        return word + "yay"


def main():
    n = int(input())
    for _ in range(n):
        words = input().split()
        translated = []
        for word in words:
            translated.append(translate(word))
        print(" ".join(translated))


main()
