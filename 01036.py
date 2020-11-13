from string import digits, ascii_uppercase


alphanumerics = digits + ascii_uppercase


def base_10_to_36(number):
    ret = ""
    while number:
        ret = alphanumerics[number % 36] + ret
        number //= 36
    if ret:
        return ret
    else:
        return "0"


def main():
    numbers = []
    frequencies = {x: 0 for x in alphanumerics[:-1]}
    for _ in range(int(input())):
        number = input()
        for ind, val in enumerate(number[::-1]):
            if val != 'Z':
                frequencies[val] += 36 ** ind * (35-alphanumerics.find(val))
        numbers.append(number)
    k = int(input())
    if k == 0:
        change = []
    else:
        change = sorted(frequencies.keys(), key=lambda x: (frequencies[x], -alphanumerics.find(x)), reverse=True)[:k]
    total = 0
    for number in numbers:
        conv = 0
        for c in number:
            if c in change:
                conv = 36 * conv + 35
            else:
                conv = 36 * conv + alphanumerics.find(c)
        total += conv
    print(base_10_to_36(total))


main()
