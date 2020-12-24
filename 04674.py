import sys
import string

TEXT_TO_NUMBER = {string.ascii_lowercase[i]: i + 1 for i in range(26)}
TEXT_TO_NUMBER.update({"_": 0, ".": 27})
NUMBER_TO_TEXT = {val: key for key, val in TEXT_TO_NUMBER.items()}


def main():
    while True:
        line = sys.stdin.readline().rstrip()
        if line == "0":
            break
        entries = line.split()
        k, ciphertext = int(entries[0]), entries[1]
        n = len(ciphertext)
        ciphercode = [TEXT_TO_NUMBER[c] for c in ciphertext]
        plaincode = [-1] * n
        for i in range(n):
            plaincode[k * i % n] = (ciphercode[i] + i) % 28
        plaintext = "".join(NUMBER_TO_TEXT[num] for num in plaincode)
        sys.stdout.write(plaintext + "\n")


main()
