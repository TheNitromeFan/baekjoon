import sys


def main():
    codes = "*?/+!"
    while True:
        word = sys.stdin.readline().rstrip()
        if word == "#":
            break
        repeats = {}
        seen = set()
        repeated_letter_count = 0
        answer = ""
        for char in word:
            if char.lower() in repeats:
                answer += repeats[char.lower()]
            elif char.lower() in seen:
                repeats[char.lower()] = codes[repeated_letter_count]
                repeated_letter_count += 1
                answer += repeats[char.lower()]
            else:
                answer += char
            seen.add(char.lower())
        print(answer)


main()
