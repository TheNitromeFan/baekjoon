import sys


def main():
    lines = ["qwertyuiop", "asdfghjkl", "zxcvbnm"]
    keyboard = {}
    for i, line in enumerate(lines):
        for j, letter in enumerate(line):
            keyboard[letter] = (i, j)
    t = int(sys.stdin.readline())
    for _ in range(t):
        word, n = sys.stdin.readline().split()
        n = int(n)
        words = []
        for _ in range(n):
            word1 = sys.stdin.readline().rstrip()
            dist = 0
            for i in range(len(word1)):
                letter, letter1 = word[i], word1[i]
                dist += abs(keyboard[letter][0] - keyboard[letter1][0]) + abs(keyboard[letter][1] - keyboard[letter1][1])
            words.append((word1, dist))
        words.sort(key=lambda x: (x[1], x[0]))
        for word1, dist in words:
            sys.stdout.write(f"{word1} {dist}\n")


main()
