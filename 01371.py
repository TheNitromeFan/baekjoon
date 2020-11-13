import sys
import string


def main():
    lines = "".join(line.rstrip().replace(" ", "") for line in sys.stdin.readlines())
    counts = [(x, lines.count(x)) for x in string.ascii_lowercase]
    counts.sort(key=lambda x: x[1], reverse=True)
    print("".join(x[0] for x in counts if x[1] == counts[0][1]))


main()
