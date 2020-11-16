import sys


def convert_base(keys, word, base):
    ret = 0
    for letter in word:
        ret *= base
        ret += keys[letter]
    return ret


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        line = sys.stdin.readline().rstrip()
        base = 2
        keys = {line[0]: 1}
        for letter in line:
            if letter in keys:
                continue
            if len(keys) == 1:
                keys[letter] = 0
            else:
                keys[letter] = base
                base += 1
        print("Case #{}: {}".format(a0, convert_base(keys, line, base)))


main()
