import sys


def main():
    leet = {"0": "O", "1": "L", "2": "Z", "3": "E", "5": "S", "6": "B", "7": "T", "8": "B"}
    n, m = (int(x) for x in sys.stdin.readline().split())
    words = set()
    for _ in range(n):
        words.add(sys.stdin.readline().rstrip())
    for _ in range(m):
        plate = sys.stdin.readline().rstrip()
        for symbol in leet:
            plate = plate.replace(symbol, leet[symbol])
        if any(word in plate for word in words):
            sys.stdout.write("INVALID\n")
        else:
            sys.stdout.write("VALID\n")


main()
