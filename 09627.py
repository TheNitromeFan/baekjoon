import sys


def main():
    letters = {1: "one", 2: "two", 3: "three", 4: "four", 5: "five", 6: "six", 7: "seven", 8: "eight", 9: "nine",
               10: "ten", 11: "eleven", 12: "twelve", 13: "thirteen", 14: "fourteen", 15: "fifteen",
               16: "sixteen", 17: "seventeen", 18: "eighteen", 19: "nineteen", 20: "twenty", 30: "thirty",
               40: "forty", 50: "fifty", 60: "sixty", 70: "seventy", 80: "eighty", 90: "ninety"}
    for i in range(20, 100, 10):
        for j in range(1, 10):
            letters[i + j] = letters[i] + letters[j]
    for i in range(100, 1000, 100):
        for j in range(1, 100):
            letters[i + j] = letters[i // 100] + "hundred" + letters[j]
    n = int(sys.stdin.readline())
    words = []
    letter_count = 0
    for _ in range(n):
        word = sys.stdin.readline().rstrip()
        words.append(word)
        letter_count += len(word)
    letter_count -= 1
    for number in letters:
        if letter_count + len(letters[number]) == number:
            words[words.index("$")] = letters[number]
            print(" ".join(words))
            return


main()
