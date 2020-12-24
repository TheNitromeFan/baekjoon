import sys
import itertools


def can_form(formation, players):
    o, v, n = formation
    o -= players.count("O")
    v -= players.count("V")
    n -= players.count("N")
    a, b, c, d = players.count("NO"), players.count("NV"), players.count("OV"), players.count("NOV")
    return o <= a + c + d and v <= b + c + d and n <= a + b + d and o + v <= a + b + c + d and o + n <= a + b + c + d\
        and v + n <= a + b + c + d and o + v + n <= a + b + c + d


def main():
    n = int(sys.stdin.readline())
    formations = []
    for _ in range(n):
        formations.append([int(x) for x in sys.stdin.readline().split("-")])
    m = int(sys.stdin.readline())
    players = []
    for _ in range(m):
        positions = sys.stdin.readline().rstrip()
        players.append("".join(sorted(positions)))
    for formation in formations:
        if can_form(formation, players):
            sys.stdout.write("DA\n")
        else:
            sys.stdout.write("NE\n")


main()
