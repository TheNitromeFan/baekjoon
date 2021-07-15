import sys


def solve(a, b):
    ret = 0
    for n in range(a, b):
        sn = str(n)
        start = sn
        while True:
            start = start[-1] + start[:-1]
            if start[0] != "0" and n < int(start) <= b:
                ret += 1
            elif start == sn:
                break
    return ret


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        a, b = (int(x) for x in sys.stdin.readline().split())
        sys.stdout.write(f"Case #{a0}: {solve(a, b)}\n")


main()
