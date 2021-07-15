import sys


def slump(s):
    if not s or s[0] not in "DE":
        return False
    if len(s) == 1 or s[1] != "F":
        return False
    idx = 1
    while idx < len(s) and s[idx] == "F":
        idx += 1
    if idx == len(s):
        return False
    elif s[idx] == "G":
        return idx + 1 == len(s)
    else:
        return slump(s[idx:])


def slimp(s):
    if len(s) <= 1 or s[0] != "A":
        return False
    if len(s) == 2:
        return s == "AH"
    if s[1] == "B":
        return s[-1] == "C" and slimp(s[2:-1])
    else:
        return s[-1] == "C" and slump(s[1:-1])


def slurpy(s):
    for idx in range(len(s) + 1):
        if slimp(s[:idx]) and slump(s[idx:]):
            return True
    return False


def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        word = sys.stdin.readline().rstrip()
        if slurpy(word):
            sys.stdout.write("YES\n")
        else:
            sys.stdout.write("NO\n")


main()
