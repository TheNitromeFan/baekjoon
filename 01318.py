import itertools
import math


suits = ["H", "D", "S", "C"]
numbers = ["A", 2, 3, 4, 5, 6, 7, 8, 9, 10, "J", "Q", "K"]
cards = [(suit, number) for suit in suits for number in numbers]
hands = {point: 0 for point in range(1, 13)}


def points(hand_of_5):
    hand_of_5.sort(key=lambda x: numbers.index(x[1]))
    if hand_of_5[0][0] == hand_of_5[1][0] == hand_of_5[2][0] == hand_of_5[3][0] == hand_of_5[4][0] \
        and hand_of_5[0][1] == "A" and hand_of_5[1][1] == 2 and hand_of_5[2][1] == 3 \
            and hand_of_5[3][1] == 4 and hand_of_5[4][1] == 5:
        return 12
    elif hand_of_5[0][0] == hand_of_5[1][0] == hand_of_5[2][0] == hand_of_5[3][0] == hand_of_5[4][0] \
        and numbers.index(hand_of_5[0][1]) + 4 == numbers.index(hand_of_5[1][1]) + 3 \
            == numbers.index(hand_of_5[2][1]) + 2 == numbers.index(hand_of_5[3][1]) + 1 \
            == numbers.index(hand_of_5[4][1]):
        return 11
    elif hand_of_5[0][1] == hand_of_5[1][1] == hand_of_5[2][1] == hand_of_5[3][1] \
            or hand_of_5[1][1] == hand_of_5[2][1] == hand_of_5[3][1] == hand_of_5[4][1]:
        return 10
    elif (hand_of_5[0][1] == hand_of_5[1][1] == hand_of_5[2][1] and hand_of_5[3][1] == hand_of_5[4][1]) \
            or (hand_of_5[0][1] == hand_of_5[1][1] and hand_of_5[2][1] == hand_of_5[3][1] == hand_of_5[4][1]):
        return 9
    elif hand_of_5[0][0] == hand_of_5[1][0] == hand_of_5[2][0] == hand_of_5[3][0] == hand_of_5[4][0]:
        return 8
    elif hand_of_5[0][1] == "A" and hand_of_5[1][1] == 10 and hand_of_5[2][1] == "J" and hand_of_5[3][1] == "Q" \
            and hand_of_5[4][1] == "K":
        return 7
    elif hand_of_5[0][1] == "A" and hand_of_5[1][1] == 2 and hand_of_5[2][1] == 3 \
            and hand_of_5[3][1] == 4 and hand_of_5[4][1] == 5:
        return 6
    elif numbers.index(hand_of_5[0][1]) + 4 == numbers.index(hand_of_5[1][1]) + 3 \
            == numbers.index(hand_of_5[2][1]) + 2 == numbers.index(hand_of_5[3][1]) + 1 \
            == numbers.index(hand_of_5[4][1]):
        return 5
    elif hand_of_5[0][1] == hand_of_5[1][1] == hand_of_5[2][1] or hand_of_5[1][1] == hand_of_5[2][1] == hand_of_5[3][1]\
            or hand_of_5[2][1] == hand_of_5[3][1] == hand_of_5[4][1]:
        return 4
    elif (hand_of_5[0][1] == hand_of_5[1][1] and hand_of_5[2][1] == hand_of_5[3][1]) \
        or (hand_of_5[0][1] == hand_of_5[1][1] and hand_of_5[3][1] == hand_of_5[4][1]) \
            or (hand_of_5[1][1] == hand_of_5[2][1] and hand_of_5[3][1] == hand_of_5[4][1]):
        return 3
    elif hand_of_5[0][1] == hand_of_5[1][1] or hand_of_5[1][1] == hand_of_5[2][1] \
            or hand_of_5[2][1] == hand_of_5[3][1] or hand_of_5[3][1] == hand_of_5[4][1]:
        return 2
    else:
        return 1


def main():
    total = 0
    for hand_of_6 in itertools.combinations(cards, 6):
        score = max(points(list(hand_of_5)) for hand_of_5 in itertools.combinations(hand_of_6, 5))
        hands[score] += 1
        total += 1
        if total % 100000 == 0:
            print(total)
    with open("01318.txt", "w") as f:
        for score in hands:
            g = math.gcd(hands[score], total)
            f.write("{}/{}\n".format(hands[score] // g, total // g))


main()
