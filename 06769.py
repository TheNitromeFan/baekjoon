def main():
    values = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    aromatic = input()
    n = len(aromatic)
    arabic = [int(aromatic[x]) for x in range(0, n, 2)]
    roman = [aromatic[x] for x in range(1, n, 2)]
    value = 0
    for i in range(n // 2 - 1):
        if values[roman[i]] < values[roman[i + 1]]:
            value -= arabic[i] * values[roman[i]]
        else:
            value += arabic[i] * values[roman[i]]
    value += arabic[-1] * values[roman[-1]]
    print(value)


main()
