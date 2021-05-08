import sys


def can_combine(intervals, n):
    for i in range(n):
        for j in range(i):
            ai, bi = intervals[i]
            aj, bj = intervals[j]
            if bj + 1 >= ai:
                intervals.pop(i)
                intervals.pop(j)
                intervals.append((min(ai, aj), max(bi, bj)))
                intervals.sort()
                return True
    return False


def main():
    intervals = []
    for line in sys.stdin.readlines():
        line = line.rstrip(" ||\n")
        entries = line.split()
        if "&&" in entries:
            a, b = int(entries[2]), int(entries[6])
            if a <= b:
                intervals.append((a, b))
        elif ">=" in entries:
            a = int(entries[2])
            intervals.append((a, 32767))
        else:
            b = int(entries[2])
            intervals.append((-32768, b))
    if not intervals:
        print("false")
        return
    n = len(intervals)
    intervals.sort()
    # print(intervals)
    while can_combine(intervals, n):
        # print(intervals)
        n -= 1
    if (-32768, 32767) in intervals:
        print("true")
        return
    to_print = []
    for a, b in intervals:
        if a == -32768:
            to_print.append(f"x <= {b}")
        elif b == 32767:
            to_print.append(f"x >= {a}")
        else:
            to_print.append(f"x >= {a} && x <= {b}")
    print(" ||\n".join(to_print))


main()
