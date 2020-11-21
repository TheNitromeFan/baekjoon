import sys
import string
import random


def has_all_bigrams(words, letter1):
    for letter2 in string.ascii_uppercase:
        if letter1 == letter2:
            continue
        if not (letter1 + letter2 in words and letter2 + letter1 in words):
            return False
    return True


def multiple_starts_or_ends(words, letter1, letter2):
    count1, count2 = 0, 0
    for letter3 in string.ascii_uppercase:
        if letter1 != letter3 and letter1 + letter3 in words:
            count1 += 1
        if letter2 != letter3 and letter2 + letter3 in words:
            count2 += 1
    if count1 == count2 == 25:
        return True
    count1, count2 = 0, 0
    for letter3 in string.ascii_uppercase:
        if letter1 != letter3 and letter3 + letter1 in words:
            count1 += 1
        if letter2 != letter3 and letter3 + letter2 in words:
            count2 += 1
    if count1 == count2 == 25:
        return True
    return False


def print_password(words, x):
    if any(len(word) == 1 for word in words):
        sys.stdout.write("Case #{}: IMPOSSIBLE\n".format(x))
        return
    for letter1 in string.ascii_uppercase:
        if has_all_bigrams(words, letter1):
            sys.stdout.write("Case #{}: IMPOSSIBLE\n".format(x))
            return
    for letter1 in string.ascii_uppercase:
        for letter2 in string.ascii_uppercase:
            if letter1 == letter2:
                continue
            if multiple_starts_or_ends(words, letter1, letter2):
                sys.stdout.write("Case #{}: IMPOSSIBLE\n".format(x))
                return
    for _ in range(50000):
        candidate = list(string.ascii_uppercase)
        random.shuffle(candidate)
        if all(word not in "".join(candidate) for word in words):
            sys.stdout.write("Case #{}: {}\n".format(x, "".join(candidate)))
            return
    sys.stdout.write("Case #{}: IMPOSSIBLE\n".format(x))


def main():
    t = int(sys.stdin.readline())
    for x in range(1, t + 1):
        n = int(sys.stdin.readline())
        words = sys.stdin.readline().rstrip().split()
        print_password(words, x)


main()
