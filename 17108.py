import sys


def read_ints(lines):
    ret = []
    cur = ""
    pos = 0
    while pos < len(lines):
        while pos < len(lines) and lines[pos] == " ":
            pos += 1
        while pos < len(lines) and lines[pos] != " ":
            cur += lines[pos]
            pos += 1
        ret.append(int(cur))
        cur = ""
    return ret


def main():
    lines = " ".join(line.rstrip() for line in sys.stdin.readlines())
    values = read_ints(lines)
    n, l, r = values[0], values[1], values[2]
    pie = values[3:]
    if len(pie) > n:
        pie = pie[:n]
    elif len(pie) < n:
        pie += [0] * (n - len(pie))
    ans = 10 ** 100
    for length in range(l, r + 1):
        boxes = 0
        cur = 0
        for i in range(n):
            if pie[i] == 0:
                if cur > 0:
                    boxes += 2
                    cur = 0
                else:
                    boxes += 1
            else:
                if cur + pie[i] <= length:
                    cur += pie[i]
                else:
                    boxes += 1
                    cur = pie[i]
        if cur > 0:
            boxes += 1
            cur = 0
        ans = min(ans, length * boxes)
    print(ans)


main()
