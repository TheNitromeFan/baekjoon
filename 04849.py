import sys


def card_rank(x):
    if x == "A":
        return 4
    elif x == "K":
        return 3
    elif x == "Q":
        return 2
    elif x == "J":
        return 1
    else:
        return 0


def stops(suit_cards):
    ret = 0
    for cards in suit_cards.values():
        if "A" in cards:
            ret += 1
        elif "K" in cards and len(cards) >= 2:
            ret += 1
        elif "Q" in cards and len(cards) >= 3:
            ret += 1
        elif "J" in cards and len(cards) >= 4:
            ret += 1
    return ret


def main():
    t = 0
    while True:
        try:
            line = sys.stdin.readline().rstrip()
        except EOFError:
            return
        if line == "":
            break
        t += 1
        cards = line.split()
        suit_cards = {"Spades": [], "Hearts": [], "Diamonds": [], "Clubs": []}
        high_card_points = 0
        for card in cards:
            suit, face = card[0], card[1]
            if suit == "S":
                suit_cards["Spades"].append(face)
            elif suit == "H":
                suit_cards["Hearts"].append(face)
            elif suit == "D":
                suit_cards["Diamonds"].append(face)
            else:
                suit_cards["Clubs"].append(face)
            high_card_points += card_rank(face)
        suit_counts = {suit: len(val) for suit, val in suit_cards.items()}
        distribution = sorted(suit_counts.values(), reverse=True)
        bid = "Pass"
        if high_card_points >= 10 and distribution[0] >= 8:
            for suit, count in suit_counts.items():
                if count == distribution[0]:
                    bid = f"4 {suit}"
                    break
        elif 10 <= high_card_points <= 13 and distribution[0] == 7:
            for suit, count in suit_counts.items():
                if count == 7:
                    bid = f"3 {suit}"
                    break
        elif 8 <= high_card_points <= 9 and distribution[0] >= 7 \
                and distribution[0] in [suit_counts["Spades"], suit_counts["Hearts"]]:
            if suit_counts["Spades"] == distribution[0]:
                bid = "2 Spades"
            else:
                bid = "2 Hearts"
        elif 8 <= high_card_points <= 11 and distribution[0] == 6 \
                and 6 in [suit_counts["Spades"], suit_counts["Hearts"]]:
            if suit_counts["Spades"] == 6:
                bid = "2 Spades"
            else:
                bid = "2 Hearts"
        elif 11 <= high_card_points <= 15 and distribution in [[4, 4, 4, 1], [5, 4, 4, 0]] \
                and suit_counts["Spades"] >= 4:
            bid = "2 Diamonds"
        elif 15 <= high_card_points <= 17 and distribution in [[4, 3, 3, 3], [4, 4, 3, 2], [5, 3, 3, 2]] \
                and stops(suit_cards) >= 3:
            bid = "1 No Trump"
        elif 20 <= high_card_points <= 22 and distribution in [[4, 3, 3, 3], [4, 4, 3, 2], [5, 3, 3, 2]]:
            bid = "2 No Trump"
        elif high_card_points >= 22:
            bid = "2 Clubs"
        elif 13 <= high_card_points <= 16:
            if suit_counts["Spades"] >= 5 or suit_counts["Hearts"] >= 5:
                if suit_counts["Spades"] >= suit_counts["Hearts"]:
                    bid = "1 Spades"
                else:
                    bid = "1 Hearts"
            else:
                if suit_counts["Diamonds"] >= suit_counts["Clubs"]:
                    bid = "1 Diamonds"
                else:
                    bid = "1 Clubs"
        elif high_card_points >= 17:
            for suit in ["Clubs", "Diamonds", "Hearts", "Spades"]:
                if suit_counts[suit] == distribution[0]:
                    bid = f"1 {suit}"
                    break
        print(f"Hand #{t}: {bid}")


main()
