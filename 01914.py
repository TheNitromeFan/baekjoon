def hanoi(layer, start, end, third):
    if layer == 0:
        return
    else:
        hanoi(layer - 1, start, third, end)
        print("{} {}".format(start, end))
        hanoi(layer - 1, third, end, start)


def main():
    n = int(input())
    print(2 ** n - 1)
    if n <= 20:
        hanoi(n, 1, 3, 2)


main()
