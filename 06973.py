import sys


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        dictionary = {}
        word_count = 0
        while True:
            line = sys.stdin.readline().rstrip()
            if not line:
                break
            new_words = []
            for word in line.split():
                if word in dictionary:
                    new_words.append(dictionary[word])
                else:
                    word_count += 1
                    dictionary[word] = str(word_count)
                    new_words.append(word)
            sys.stdout.write(" ".join(new_words) + "\n")
        sys.stdout.write("\n")


main()
