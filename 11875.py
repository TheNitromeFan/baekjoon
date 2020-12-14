import sys
import string
import math


def is_root(s, t):
    if len(s) % len(t) != 0:
        return False
    return all(sorted(t) == sorted(s[i: i + len(t)]) for i in range(len(t), len(s), len(t)))


def root(s):
    letter_counts = {x: s.count(x) for x in string.ascii_lowercase}
    div = 0
    for val in letter_counts.values():
        div = math.gcd(div, val)
    for x in range(div, 1, -1):
        if len(s) % x != 0:
            continue
        t = s[:len(s) // x]
        if is_root(s, t):
            return t
    return "-1"


def main():
    s = sys.stdin.readline().rstrip()
    sys.stdout.write(root(s))


main()
