def ee(low, digit):
    for e in range(low + 1, 63):
        if str(2 ** e)[0] == str(digit):
            return e
    return 0


def main():
    a, b = (int(x) for x in input().split())
    print(ee(a, b))


main()
