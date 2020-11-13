import sys


letter_to_morse = {'A': '.-', 'B': '-...', 'C': '-.-.', 'D': '-..', 'E': '.', 'F': '..-.', 'G': '--.',
                   'H': '....', 'I': '..', 'J': '.---', 'K': '-.-', 'L': '.-..', 'M': '--', 'N': '-.',
                   'O': '---', 'P': '.--.', 'Q': '--.-', 'R': '.-.', 'S': '...', 'T': '-', 'U': '..-',
                   'V': '...-', 'W': '.--', 'X': '-..-', 'Y': '-.--', 'Z': '--..',
                   '_': '..--', ',': '.-.-', '.': '---.', '?': '----'}
morse_to_letter = {v: k for k, v in letter_to_morse.items()}


def encode(s):
    return ''.join(letter_to_morse[letter] for letter in s), [len(letter_to_morse[letter]) for letter in s]


def decode(s, lengths):
    ret = ''
    index = 0
    for number in lengths:
        ret += morse_to_letter[s[index: index + number]]
        index += number
    return ret


def main():
    n = int(sys.stdin.readline())
    for i in range(1, n + 1):
        line = sys.stdin.readline().rstrip()
        morse, lengths = encode(line)
        print('{}: {}'.format(i, decode(morse, lengths[::-1])))


main()
