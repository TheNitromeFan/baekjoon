import sys


def count_differences(s1, s2):
    ret = 0
    for a, b in zip(s1, s2):
        if a != b:
            ret += 1
    return ret


def judge(commands1, commands2, strings1, strings2):
    if commands1 != commands2 or len(strings1) != len(strings2):
        return "DIFFERENT"
    c = count_differences(strings1, strings2)
    if c == 0:
        return "IDENTICAL"
    elif c == 1:
        return "CLOSE"
    else:
        return "DIFFERENT"


def main():
    while True:
        s1 = sys.stdin.readline().rstrip()
        if s1 == '.':
            break
        s2 = sys.stdin.readline().rstrip()
        entries1 = s1.split('"')
        entries2 = s2.split('"')
        commands1 = [entry for i, entry in enumerate(entries1) if i % 2 == 0]
        commands2 = [entry for i, entry in enumerate(entries2) if i % 2 == 0]
        strings1 = [entry for i, entry in enumerate(entries1) if i % 2 == 1]
        strings2 = [entry for i, entry in enumerate(entries2) if i % 2 == 1]
        print(judge(commands1, commands2, strings1, strings2))


main()
