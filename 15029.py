import sys


def main():
    balls = {"red": 1, "yellow": 2, "green": 3, "brown": 4, "blue": 5, "pink": 6, "black": 7}
    table = {"red": 0}
    n = int(sys.stdin.readline())
    for _ in range(n):
        color = sys.stdin.readline().rstrip()
        if color in table:
            table[color] += 1
        else:
            table[color] = 1
    max_color = max(table.keys(), key=lambda x: balls[x])
    if max_color == "red":
        print(1)
        return
    points = balls[max_color] * (table["red"] + 1) + table["red"]
    for color in table:
        if color not in ["red", max_color]:
            points += balls[color]
    print(points)


main()
