import sys


def define(word):
    start, end = [], []
    if word[:4] == "anti":
        start = start + ["against"]
        word = word[4:]
    elif word[:4] == "post":
        start = start + ["after"]
        word = word[4:]
    elif word[:3] == "pre":
        start = start + ["before"]
        word = word[3:]
    elif word[:2] == "re":
        end = ["again"] + end
        word = word[2:]
    elif word[:2] == "un":
        start = start + ["not"]
        word = word[2:]
    if word[-2:] == "er":
        start = start + ["one", "who"]
        word = word[:-2] + "s"
    elif word[-3:] == "ing":
        start = start + ["to", "actively"]
        word = word[:-3]
    elif word[-3:] == "ize":
        start = start + ["change", "into"]
        word = word[:-3]
    elif word[-1] == "s":
        start = start + ["multiple", "instances", "of"]
        word = word[:-1]
    elif word[-4:] == "tion":
        start = start + ["the", "process", "of"]
        word = word[:-4] + "ing"
    return " ".join(start + [word] + end)


def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        word = sys.stdin.readline().rstrip()
        sys.stdout.write(define(word) + "\n")


main()
