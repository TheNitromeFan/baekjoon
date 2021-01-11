import sys
import string


sys.setrecursionlimit(10 ** 6)


def parse(line):
    words = []
    word = ""
    for c in line:
        if c in string.ascii_letters:
            word += c
        else:
            if word:
                words.append(word)
            word = ""
    if word:
        words.append(word)
    return words


def final_word(dest, words, threshold, idx):
    if threshold <= idx < len(words):
        return words[idx]
    elif idx >= len(words):
        return "-outside-"
    elif idx in dest:
        return dest[idx]
    dest[idx] = final_word(dest, words, threshold, idx + len(words[idx]))
    return dest[idx]


def magic_trick(words1, words2, words3):
    ans = set()
    dest = {}
    words = words1 + words2 + words3
    threshold = len(words1) + len(words2)
    for idx, _ in enumerate(words1):
        ans.add(final_word(dest, words, threshold, idx).lower())
        if len(ans) > 3:
            return ["-too many-"]
    return sorted(ans)


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        words1 = parse(sys.stdin.readline().rstrip())
        words2 = parse(sys.stdin.readline().rstrip())
        words3 = parse(sys.stdin.readline().rstrip())
        print(f"Scenario #{a0}:")
        print("\n".join(magic_trick(words1, words2, words3)) + "\n")


main()
