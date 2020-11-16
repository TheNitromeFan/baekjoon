import sys
import itertools


def main():
    t = int(sys.stdin.readline())
    for i in range(1, t + 1):
        string = sys.stdin.readline().rstrip()
        sys.stdout.write("Case # {}:\n".format(i))
        for permutation in itertools.permutations(string):
            sys.stdout.write("".join(permutation) + "\n")


main()
