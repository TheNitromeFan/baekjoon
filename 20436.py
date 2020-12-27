import sys


def dist(a, b):
    return abs(a[0] - b[0]) + abs(a[1] - b[1])


def keyboard_type(sl, sr, word):
    left = {"q": (1, 1), "w": (1, 2), "e": (1, 3), "r": (1, 4), "t": (1, 5), "a": (2, 1), "s": (2, 2), "d": (2, 3),
            "f": (2, 4), "g": (2, 5), "z": (3, 1), "x": (3, 2), "c": (3, 3), "v": (3, 4)}
    right = {"y": (1, 6), "u": (1, 7), "i": (1, 8), "o": (1, 9), "p": (1, 10), "h": (2, 6), "j": (2, 7), "k": (2, 8),
             "l": (2, 9), "b": (3, 5), "n": (3, 6), "m": (3, 7)}
    ret = 0
    for char in word:
        if char in left:
            ret += dist(left[sl], left[char])
            sl = char
        else:
            ret += dist(right[sr], right[char])
            sr = char
        ret += 1
    return ret


def main():
    sl, sr = sys.stdin.readline().rstrip().split()
    word = sys.stdin.readline().rstrip()
    print(keyboard_type(sl, sr, word))


main()
