import sys


def replace_placeholder(s, a):
    ret = ""
    for c in s:
        if c == "$":
            ret += a
        else:
            ret += c
    return ret


def main():
    start = sys.stdin.readline().strip()
    s = sys.stdin.readline().strip()
    repetitions = int(sys.stdin.readline())
    idx_min, idx_max = (int(x) for x in sys.stdin.readline().strip().split())
    if s.count("$") >= 2 and repetitions > 30:
        repetitions = 30
    for _ in range(repetitions):
        start = replace_placeholder(s, start)
    print(start[idx_min - 1 : idx_max])


main()
