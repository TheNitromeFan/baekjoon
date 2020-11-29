import sys


def main():
    n = int(sys.stdin.readline())
    classes = []
    for _ in range(n):
        times = set([int(x) for x in sys.stdin.readline().split()][1:])
        classes.append(times)
    m = int(sys.stdin.readline())
    for _ in range(m):
        times = set([int(x) for x in sys.stdin.readline().split()][1:])
        sys.stdout.write("{}\n".format(len([s for s in classes if times.issuperset(s)])))


main()
