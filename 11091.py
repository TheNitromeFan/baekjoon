import string


n = int(input())
for _ in range(n):
    line = input().lower()
    missing_letters = "".join(letter for letter in string.ascii_lowercase if letter not in line)
    if missing_letters:
        print("missing {}".format(missing_letters))
    else:
        print("pangram")
