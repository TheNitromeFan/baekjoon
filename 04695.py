import sys
import string


def process(text):
    ret = []
    cur = ""
    for char in text:
        if char in string.ascii_uppercase:
            cur += char
        elif cur:
            ret.append(cur)
            cur = ""
    if cur:
        ret.append(cur)
    return ret


def analyze_frequencies(words, length):
    tally = {}
    for word in words:
        for i in range(len(word) + 1 - length):
            seq = word[i: i + length]
            if seq in tally:
                tally[seq] += 1
            else:
                tally[seq] = 1
    sequences = sorted(tally.keys(), key=lambda x: -tally[x])
    frequencies = []
    groups = []
    for sequence in sequences:
        if not frequencies or tally[sequence] < frequencies[-1]:
            frequencies.append(tally[sequence])
            groups.append([sequence])
        else:
            groups[-1].append(sequence)
    return frequencies[:5], groups[:5]


def main():
    text = process("".join(line.upper() for line in sys.stdin.readlines()))
    for length in range(1, 6):
        frequencies, groups = analyze_frequencies(text, length)
        sys.stdout.write(
            "Analysis for Letter Sequences of Length {}\n-----------------------------------------\n".format(length))
        for frequency, group in zip(frequencies, groups):
            sys.stdout.write("Frequency = {}, Sequence(s) = ({})\n".format(frequency, ",".join(sorted(group))))
        sys.stdout.write("\n")


main()
