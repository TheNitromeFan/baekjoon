import sys
import itertools


def is_set(c1, c2, c3):
    for i in range(4):
        if not ((c1[i] == c2[i] == c3[i]) or (c1[i] != c2[i] and c2[i] != c3[i] and c3[i] != c1[i])):
            return False
    return True


def main():
    lines = []
    for line in sys.stdin.readlines():
        lines.append(line.rstrip())
    idx = 0
    while idx < len(lines):
        deck = []
        while idx < len(lines) and lines[idx]:
            deck.append(lines[idx])
            idx += 1
        sys.stdout.write(f"CARDS:  {' '.join(deck)}\n")
        sets = []
        for card1, card2, card3 in itertools.combinations(deck, 3):
            if is_set(card1, card2, card3):
                sets.append((card1, card2, card3))
        sys.stdout.write("SETS:   ")
        if sets:
            sys.stdout.write(f"1.  {' '.join(sets[0])}\n")
            for i, triple in enumerate(sets[1:], start=2):
                sys.stdout.write(f"        {i}.  {' '.join(triple)}\n")
        else:
            sys.stdout.write("*** None Found ***\n")
        sys.stdout.write("\n")
        idx += 1


main()
