import sys
import string


def main():
    number_to_letter = {2: "ABC", 3: "DEF", 4: "GHI", 5: "JKL", 6: "MNO", 7: "PQRS", 8: "TUV", 9: "WXYZ"}
    letter_to_number = {}
    for number in number_to_letter:
        for letter in number_to_letter[number]:
            letter_to_number[letter] = number
    n = int(sys.stdin.readline())
    for _ in range(n):
        name = sys.stdin.readline().rstrip().upper()
        phone = [letter_to_number[letter] for letter in name]
        if phone == phone[::-1]:
            print("YES")
        else:
            print("NO")


main()
