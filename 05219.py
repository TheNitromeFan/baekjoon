import sys


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        productions = sys.stdin.readline().rstrip().split()
        strings = sys.stdin.readline().rstrip().split()
        transformed = []
        for string in strings:
            for idx in range(0, len(productions), 2):
                start, end = productions[idx], productions[idx + 1]
                i = string.find(start)
                if i != -1:
                    string = string[:i] + end + string[i + 1:]
            transformed.append(string)
        sys.stdout.write("Transformed strings: {}\n".format(" ".join(transformed)))


main()
