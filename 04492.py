import sys


lights = [6, 2, 5, 5, 4, 5, 6, 3, 7, 6]


def amp(n):
    if n == 0:
        return 30
    elif n < 0:
        return 5 + amp(-n)
    ret = 0
    while n:
        ret += 5 * lights[n % 10]
        n //= 10
    return ret


def preprocess():
    ret = {}
    for x in range(-999, 1000):
        ret[x] = amp(x)
    return ret


def main():
    table = preprocess()
    while True:
        entries = [int(x) for x in sys.stdin.readline().split()]
        if entries == [0]:
            break
        x, y, z = entries
        count = 0
        for a in range(-999, 1000):
            if table[a] != x:
                continue
            for b in range(-999, 1000):
                if table[b] != y:
                    continue
                if -999 <= a + b <= 999 and table[a + b] == z:
                    count += 1
                if -999 <= a - b <= 999 and table[a - b] == z:
                    count += 1
                if -999 <= a * b <= 999 and table[a * b] == z:
                    count += 1
                if b and -999 <= int(a / b) <= 999 and table[int(a / b)] == z:
                    count += 1
        if count == 1:
            print(f"1 solution for {x} {y} {z}")
        else:
            print(f"{count} solutions for {x} {y} {z}")


main()
