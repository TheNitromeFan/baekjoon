import sys


def main():
    sys.stdin.readline()
    sentence = sys.stdin.readline().rstrip().split()
    m = int(sys.stdin.readline())
    correct, total = {word: set() for word in sentence}, {word: set() for word in sentence}
    for _ in range(m):
        d, e, c = sys.stdin.readline().rstrip().split()
        if d in total:
            if c == "correct":
                correct[d].add(e)
            total[d].add(e)
    correct_count, total_count = 1, 1
    for word in sentence:
        correct_count *= len(correct[word])
        total_count *= len(total[word])
    incorrect_count = total_count - correct_count
    if all(len(correct[word]) == 1 for word in sentence):
        translated = []
        for word in sentence:
            x = correct[word].pop()
            translated.append(x)
            correct[word].add(x)
        sys.stdout.write(" ".join(translated) + "\ncorrect")
    elif all(len(total[word]) == 1 for word in sentence):
        translated = []
        for word in sentence:
            x = total[word].pop()
            translated.append(x)
            total[word].add(x)
        sys.stdout.write(" ".join(translated) + "\nincorrect")
    else:
        sys.stdout.write(f"{correct_count} correct\n{incorrect_count} incorrect")


main()
