import sys


def main():
    n = int(sys.stdin.readline())
    language = {}
    punctuation = ",.!;?()"
    for _ in range(n):
        words = sys.stdin.readline().rstrip().split()
        for word in words[1:]:
            language[word.lower()] = words[0]
    sys.stdin.readline()
    for line in sys.stdin.readlines():
        line = line.rstrip()
        for symbol in punctuation:
            line = line.replace(symbol, " ")
        for word in line.split():
            if word.lower() in language:
                print(language[word.lower()])
                break


main()
