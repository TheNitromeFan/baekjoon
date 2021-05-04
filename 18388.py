import sys


def main():
    text = sys.stdin.readline().rstrip()
    uppercase = "QWERTYUIOPASDFGHJKLZXCVBNM"
    decoded = ""
    for letter in text:
        if letter in uppercase:
            decoded += uppercase[uppercase.index(letter) + 1]
        else:
            decoded += letter
    sys.stdout.write(decoded)


main()
