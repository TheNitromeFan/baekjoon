def main():
    input()
    s = input()
    vowels = "aeiou"
    print(sum(s.count(vowel) for vowel in vowels))


main()
