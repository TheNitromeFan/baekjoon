import sys


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        m, n = (int(x) for x in sys.stdin.readline().split())
        table = {}
        for i in range(1, n + 1):
            line = sys.stdin.readline()
            for j, y in enumerate(line.split(), start=1):
                table[(i, j)] = int(y)
        max_prod = 1
        max_col = 1
        for row in range(1, n + 1):
            max_prod *= table[(row, 1)]
        for col in range(2, m + 1):
            prod = 1
            for row in range(1, n + 1):
                prod *= table[(row, col)]
            if max_prod <= prod:
                max_prod = prod
                max_col = col
        print(max_col)


main()
