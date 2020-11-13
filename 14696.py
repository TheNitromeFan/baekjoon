import sys


def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        entries = [int(x) for x in sys.stdin.readline().split()]
        card1 = [0, 0, 0, 0]
        for i in range(1, entries[0] + 1):
            card1[4 - entries[i]] += 1
        entries = [int(x) for x in sys.stdin.readline().split()]
        card2 = [0, 0, 0, 0]
        for i in range(1, entries[0] + 1):
            card2[4 - entries[i]] += 1
        if card1 > card2:
            print('A')
        elif card1 < card2:
            print('B')
        else:
            print('D')


main()
