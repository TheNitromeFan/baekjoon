import sys
import string


def main():
    keyboard = ["*"] * 3 + list(string.ascii_uppercase) + ["*"] * 3
    n = int(sys.stdin.readline())
    words = []
    for _ in range(n):
        words.append(sys.stdin.readline().rstrip())
    ticket = sys.stdin.readline().rstrip()
    letters = []
    for word in words:
        if word[:len(ticket)] == ticket and word != ticket:
            letters.append(word[len(ticket)])
    for i, val in enumerate(keyboard):
        if val not in letters:
            keyboard[i] = "*"
    sys.stdout.write("".join(keyboard[:8]) + "\n")
    sys.stdout.write("".join(keyboard[8:16]) + "\n")
    sys.stdout.write("".join(keyboard[16:24]) + "\n")
    sys.stdout.write("".join(keyboard[24:]) + "\n")


main()
