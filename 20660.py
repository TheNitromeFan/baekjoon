import sys


def main():
    a = {int(x) for x in sys.stdin.readline().split()[1:]}
    m = int(sys.stdin.readline())
    pizzas = 0
    for _ in range(m):
        b = {int(x) for x in sys.stdin.readline().split()[1:]}
        if not a & b:
            pizzas += 1
    print(pizzas)


main()
