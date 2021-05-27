import sys


values = {"o": 100, "e": 10, "g": 1, "a": 0, "b": -1, "i": -10, "u": -100}


def maximum_sum(s):
    ret = 0
    max_ending_here = 0
    for c in s:
        max_ending_here += values[c]
        ret = max(ret, max_ending_here)
        max_ending_here = max(max_ending_here, 0)
    return ret


def main():
    data = ""
    for line in sys.stdin.readlines():
        data += line.strip().replace(" ", "")
    cases = data[:-1].split(",")
    for test in cases:
        print(maximum_sum(test))


main()
