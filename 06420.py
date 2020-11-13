from string import ascii_lowercase


def format_number(n):
    n = str(n)
    ans = ""
    for i, c in enumerate(n):
        if i > 0 and (len(n) - i) % 3 == 0:
            ans += ","
        ans += c
    return ans


def format_word(word):
    return word + " " * (22 - len(word))


def word_to_number(word):
    answer = 0
    for character in word:
        answer = answer * 26 + ascii_lowercase.find(character) + 1
    return answer


def number_to_word(number):
    answer = ""
    while number:
        answer = ascii_lowercase[(number - 1) % 26] + answer
        number = (number - 1) // 26
    return answer


def is_number(s):
    try:
        int(s)
        return True
    except ValueError:
        return False


def main():
    while True:
        s = input()
        if s == "*":
            break
        if is_number(s):
            s = int(s)
            x, y = number_to_word(s), s
        else:
            x, y = s, word_to_number(s)
        print("{}{}".format(format_word(x), format_number(y)))


main()
