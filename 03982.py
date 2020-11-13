import sys


def main():
    c = int(sys.stdin.readline())
    for _ in range(c):
        goals = {}
        for _ in range(16):
            t1, t2, g1, g2 = sys.stdin.readline().rstrip().split()
            if t1 not in goals:
                goals[t1] = 0
            if t2 not in goals:
                goals[t2] = 0
            if int(g1) > int(g2):
                goals[t1] += 1
            else:
                goals[t2] += 1
        for key, value in goals.items():
            if value == 4:
                print(key)


main()
