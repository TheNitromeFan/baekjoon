import sys


def main():
    while True:
        n = int(sys.stdin.readline())
        if n == 0:
            break
        digrams = {}
        count = 0
        line = ""
        for _ in range(n):
            line += sys.stdin.readline()[:-1]
        for i in range(len(line) - 1):
            digram = line[i:i + 2]
            if digram in digrams:
                digrams[digram] += 1
            else:
                digrams[digram] = 1
            count += 1
        for key, val in sorted(digrams.items(), key=lambda x : (-x[1], x[0]))[:5]:
            sys.stdout.write("{0} {1} {2:.6f}\n".format(key, val, val / count))
        sys.stdout.write("\n")


main()
