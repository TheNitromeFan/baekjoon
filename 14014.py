import sys
import string


def main():
    of_words = ["of", "to", "into", "onto", "above", "below", "from", "by", "is", "at"]
    n = int(sys.stdin.readline())
    text = ""
    for _ in range(n):
        text += sys.stdin.readline()
    words = text.split()
    for i, word in enumerate(words):
        word = word.lower()
        if word in of_words:
            word = "of"
        new_word = ""
        for letter in word:
            if letter in string.ascii_letters:
                new_word += letter.lower()
        k = sum(new_word.count(vowel) for vowel in "aeiou")
        # print(k)
        vowel_count = 0
        final_word = ""
        for letter in new_word:
            if letter in "aeiou":
                vowel_count += 1
                if vowel_count > k // 2:
                    final_word += letter
            else:
                final_word += letter
        words[i] = final_word
    letter_count = 0
    output = ""
    for word in words:
        if not word:
            continue
        # print(word, len(word))
        letter_count += len(word)
        output += word + " "
        if letter_count > 20:
            output += "\n"
            letter_count = 0
    sys.stdout.write(output.rstrip())


main()
