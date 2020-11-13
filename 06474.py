import sys


mirror = {'A': 'A', 'E': '3', 'H': 'H', 'I': 'I', 'J': 'L', 'L': 'J', 'M': 'M', 'O': 'O', 'S': '2', 'T': 'T',
          'U': 'U', 'V': 'V', 'W': 'W', 'X': 'X', 'Y': 'Y', 'Z': '5', '1': '1', '2': 'S', '3': 'E', '5': 'Z', '8': '8'}


def is_palindrome(word):
    return word == word[::-1]


def is_mirror(word):
    return all(character in mirror for character in word) and word == ''.join(mirror[c] for c in reversed(word))


def main():
    for line in sys.stdin:
        word = line.rstrip()
        if is_palindrome(word) and is_mirror(word):
            print('{} -- is a mirrored palindrome.\n'.format(word))
        elif is_palindrome(word):
            print('{} -- is a palindrome.\n'.format(word))
        elif is_mirror(word):
            print('{} -- is a mirrored string.\n'.format(word))
        else:
            print('{} -- is not a palindrome.\n'.format(word))


main()
