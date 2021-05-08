import sys
import itertools


def strike_ball(tuple1, tuple2, c):
    strike, ball = 0, 0
    for i in range(c):
        if tuple1[i] == tuple2[i]:
            strike += tuple1[i]
        elif tuple1[i] in tuple2:
            ball += tuple1[i]
    return strike, ball


def is_code(a, b, codes, candidate, c):
    for i in range(c):
        strike, ball, code = a[i], b[i], codes[i]
        if (strike, ball) != strike_ball(candidate, code, c):
            return False
    return True


def main():
    c = int(sys.stdin.readline())
    a, b, codes = [], [], []
    for _ in range(c):
        entries = [int(x) for x in sys.stdin.readline().split()]
        a.append(entries[0])
        b.append(entries[1])
        codes.append(tuple(entries[2:]))
    for perm in itertools.permutations(range(10), r=c):
        if is_code(a, b, codes, perm, c):
            print(" ".join(str(x) for x in perm))
            break


main()
