def main():
    name = input()
    letter_counts = {x: name.count(x) for x in name}
    odd_letters = [letter for letter in letter_counts if letter_counts[letter] % 2 == 1]
    if len(odd_letters) > 1:
        print("I'm Sorry Hansoo")
        return
    first_half = "".join(sorted(letter * (letter_counts[letter] // 2) for letter in letter_counts))
    if odd_letters:
        print(first_half + odd_letters[0] + first_half[::-1])
    else:
        print(first_half + first_half[::-1])


main()
