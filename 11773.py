import sys
import string
import itertools


def main():
    a, b = (int(x) for x in sys.stdin.readline().split())
    words = []
    count = 0
    length = 1
    while True:
        for p in itertools.product(string.ascii_lowercase, repeat=length):
            words.append("".join(p))
            count += 1
            if count == max(a, (b + 1) // 2):
                print(" ".join(words))
                return
        length += 1


main()
