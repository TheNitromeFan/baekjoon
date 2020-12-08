import sys
import itertools


def is_set(cards):
    for i in range(4):
        if not (cards[0][i] != cards[1][i] and cards[1][i] != cards[2][i] and cards[2][i] != cards[0][i]
           or cards[0][i] == cards[1][i] == cards[2][i]):
            return False
    return True


def main():
    cards = []
    for line in sys.stdin.readlines():
        card = line.rstrip()
        if card:
            cards.append(card)
            continue
        sets = []
        for hand in itertools.combinations(cards, 3):
            if is_set(hand):
                sets.append(hand)
        sys.stdout.write("CARDS:  {}\n".format(" ".join(cards)))
        sys.stdout.write("SETS:   ")
        answer = ["{}.  {}".format(i, " ".join(hand)) for i, hand in enumerate(sets, start=1)]
        if answer:
            sys.stdout.write("\n        ".join(answer))
        else:
            sys.stdout.write("*** None Found ***")
        sys.stdout.write("\n\n")
        cards = []
    sets = []
    for hand in itertools.combinations(cards, 3):
        if is_set(hand):
            sets.append(hand)
    sys.stdout.write("CARDS:  {}\n".format(" ".join(cards)))
    sys.stdout.write("SETS:   ")
    answer = ["{}.  {}".format(i, " ".join(hand)) for i, hand in enumerate(sets, start=1)]
    if answer:
        sys.stdout.write("\n        ".join(answer))
    else:
        sys.stdout.write("*** None Found ***")


main()
