import sys


def main():
    p = int(sys.stdin.readline())
    for _ in range(p):
        alphabet = sys.stdin.readline()[:-1]
        sys.stdin.readline()
        deltas = [int(x) for x in sys.stdin.readline().split()]
        pos = 0
        s = ""
        for delta in deltas:
            pos = (pos + delta) % len(alphabet)
            s += alphabet[pos]
        sys.stdout.write("{}\n".format(s))


main()
