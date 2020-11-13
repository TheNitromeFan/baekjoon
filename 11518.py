import sys


def convert_to_morse(word, codes):
    ret = ""
    for letter in word:
        ret += codes[letter]
    return ret


def match(words, code, codes):
    for word in words:
        if convert_to_morse(word, codes) == code:
            return word


def main():
    codes = {}
    for _ in range(26):
        letter, code = sys.stdin.readline().rstrip().split()
        codes[letter] = code
    n = int(sys.stdin.readline())
    words = []
    for _ in range(n):
        word = sys.stdin.readline().rstrip()
        words.append(word)
    while True:
        w = int(sys.stdin.readline().rstrip())
        if w == 0:
            break
        decoded = []
        for _ in range(w):
            code = sys.stdin.readline().rstrip()
            m = match(words, code, codes)
            decoded.append((code, m))
        for code, m in decoded:
            if m is None:
                print("{} not in dictionary.".format(code))
                break
        else:
            print(" ".join(m for _, m in decoded))


main()
