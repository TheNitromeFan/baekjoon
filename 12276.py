import sys


NOUNS = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
ADJECTIVES = ["", "", "double", "triple", "quadruple", "quintuple",
              "sextuple", "septuple", "octuple", "nonuple", "decuple"]


def pronounce(block):
    ret = []
    pos = 0
    while pos < len(block):
        start = pos
        cnt = 0
        while pos < len(block) and block[pos] == block[start]:
            pos += 1
            cnt += 1
        if cnt > 10:
            ret += [NOUNS[int(block[start])]] * cnt
        elif cnt >= 2:
            ret += [ADJECTIVES[cnt], NOUNS[int(block[start])]]
        else:
            ret += [NOUNS[int(block[start])]]
    return ret


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        n, f = sys.stdin.readline().rstrip().split()
        dividers = [int(x) for x in f.split("-")]
        blocks = []
        pos = 0
        for divider in dividers:
            blocks.append(n[pos:pos+divider])
            pos += divider
        words = []
        for block in blocks:
            words += pronounce(block)
        print(f"Case #{a0}: {' '.join(words)}")


main()
