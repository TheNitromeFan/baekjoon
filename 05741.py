import sys


def main():
    while True:
        n = int(sys.stdin.readline())
        if n == 0:
            break
        table = {}
        goals = {}
        for _ in range(n):
            match = sys.stdin.readline().rstrip()
            club1, x, _, y, club2 = match.split()
            x, y = int(x), int(y)
            if club1 not in table:
                table[club1] = 0
                goals[club1] = 0
            if club2 not in table:
                table[club2] = 0
                goals[club2] = 0
            if x > y:
                table[club1] += 3
            elif x < y:
                table[club2] += 3
            else:
                table[club1] += 1
                table[club2] += 1
            goals[club1] += x - y
            goals[club2] += y - x
        results = sorted(table.keys(), key=lambda x: (table[x], goals[x]), reverse=True)
        for club in results:
            sys.stdout.write("{} {}\n".format(table[club], club))
        sys.stdout.write("\n")


main()
