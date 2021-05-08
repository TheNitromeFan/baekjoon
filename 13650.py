import sys


def main():
    while True:
        try:
            n = int(sys.stdin.readline())
        except (EOFError, ValueError):
            break
        shoes = {}
        count = 0
        for _ in range(n):
            entries = sys.stdin.readline().rstrip().split()
            size, side = int(entries[0]), entries[1]
            if size not in shoes:
                shoes[size] = {"D": 0, "E": 0}
            shoes[size][side] += 1
            if shoes[size]["D"] >= 1 and shoes[size]["E"] >= 1:
                count += 1
                shoes[size]["D"] -= 1
                shoes[size]["E"] -= 1
        print(count)


main()
