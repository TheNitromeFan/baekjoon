import sys
import itertools


def win(a, b, c, d):
    if a == b and c == d:
        return a > c
    elif a == b:
        return True
    elif c == d:
        return False
    else:
        return (a + b) % 10 > (c + d) % 10


def main():
    cards = list(range(1, 11)) * 2
    a, b = (int(x) for x in sys.stdin.readline().split())
    cards.remove(a)
    cards.remove(b)
    total, winning = 0, 0
    for c, d in itertools.combinations(cards, 2):
        total += 1
        if win(a, b, c, d):
            winning += 1
    sys.stdout.write("{0:.3f}".format(winning / total))


main()
