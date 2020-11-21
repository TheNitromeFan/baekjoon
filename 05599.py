import sys


def main():
    n = int(sys.stdin.readline())
    cards = list(range(1, 2 * n + 1))
    m = int(sys.stdin.readline())
    for _ in range(m):
        k = int(sys.stdin.readline())
        if k == 0:
            stack1, stack2 = cards[:n], cards[n:]
            for i in range(2 * n):
                if i % 2 == 0:
                    cards[i] = stack1[i // 2]
                else:
                    cards[i] = stack2[i // 2]
        else:
            cards = cards[k:] + cards[:k]
    for card in cards:
        sys.stdout.write("{}\n".format(card))


main()
