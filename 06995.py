import sys


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        cards = [int(x) for x in sys.stdin.readline().split()]
        suits = [cards[i] for i in range(0, 10, 2)]
        values = sorted(cards[i] for i in range(1, 10, 2))
        if len(set(values[i] - values[j] for i in range(5) for j in range(i))) == 10:
            sys.stdout.write("Have a spread.          ")
        else:
            sys.stdout.write("Do not have a spread.   ")
        if len(set(suits)) == 5:
            sys.stdout.write("Have a rainbow.")
        else:
            sys.stdout.write("Do not have a rainbow.")
        sys.stdout.write("\n")


main()
