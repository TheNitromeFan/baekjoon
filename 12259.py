import sys


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        answer1 = int(sys.stdin.readline())
        s1 = set()
        for i in range(4):
            s = {int(x) for x in sys.stdin.readline().split()}
            if i + 1 == answer1:
                s1 = s
        answer2 = int(sys.stdin.readline())
        s2 = set()
        for i in range(4):
            s = {int(x) for x in sys.stdin.readline().split()}
            if i + 1 == answer2:
                s2 = s
        candidates = s1 & s2
        sys.stdout.write("Case #{}: ".format(a0))
        if len(candidates) == 1:
            sys.stdout.write("{}\n".format(min(candidates)))
        elif len(candidates) > 1:
            sys.stdout.write("Bad magician!\n")
        else:
            sys.stdout.write("Volunteer cheated!\n")


main()
