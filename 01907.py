import sys
import itertools


def atom_counts(m):
    ret = {x: 0 for x in "CHO"}
    i = 0
    while i < len(m):
        if i + 1 < len(m) and "0" <= m[i + 1] <= "9":
            ret[m[i]] += int(m[i + 1])
            i += 2
        else:
            ret[m[i]] += 1
            i += 1
    return ret


def main():
    equation = sys.stdin.readline().rstrip()
    sides = equation.split("=")
    m1, m2 = sides[0].split("+")
    m3 = sides[1]
    a1, a2, a3 = atom_counts(m1), atom_counts(m2), atom_counts(m3)
    for x1, x2, x3 in itertools.product(range(1, 11), repeat=3):
        if all(x1 * a1[x] + x2 * a2[x] == x3 * a3[x] for x in "CHO"):
            print("{} {} {}".format(x1, x2, x3))
            return


main()
