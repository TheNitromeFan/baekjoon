import sys


def points(words, list1, word):
    candidates = [word1 for word1 in words if len(word1) == len(word)]
    # print(candidates)
    ret = 0
    if len(candidates) == 1:
        return ret
    for letter in list1:
        if all(letter not in candidate for candidate in candidates):
            continue
        new_candidates = []
        for candidate in candidates:
            if [x for x in range(len(word)) if candidate[x] == letter]\
              == [x for x in range(len(word)) if word[x] == letter]:
                new_candidates.append(candidate)
        candidates = new_candidates[::]
        if letter not in word:
            ret += 1
        if len(candidates) == 1:
            break
    return ret


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        n, m = (int(x) for x in sys.stdin.readline().split())
        words = []
        for _ in range(n):
            words.append(sys.stdin.readline().rstrip())
        sys.stdout.write("Case #{}:".format(a0))
        for _ in range(m):
            list1 = sys.stdin.readline().rstrip()
            max_points = -1
            max_word = ""
            for word in words:
                p = points(words, list1, word)
                # print(p)
                if p > max_points:
                    max_points = p
                    max_word = word
            sys.stdout.write(" {}".format(max_word))
        sys.stdout.write("\n")


main()
