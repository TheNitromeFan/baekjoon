import sys
import itertools
import string


def value(c):
    return string.ascii_uppercase.index(c) + 1


def evaluate(v, w, x, y, z):
    return v - w ** 2 + x ** 3 - y ** 4 + z ** 5


def main():
    while True:
        line = sys.stdin.readline().rstrip().split()
        target = int(line[0])
        alphabet = sorted(line[1])
        if target == 0 and alphabet == sorted("END"):
            break
        answer = "no solution"
        for trial in itertools.permutations(alphabet, r=5):
            if evaluate(*(value(c) for c in trial)) == target:
                answer = "".join(trial)
        print(answer)


main()
