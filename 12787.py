import sys


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        entries = sys.stdin.readline().split()
        m, n = int(entries[0]), entries[1]
        if m == 1:
            addresses = [int(x) for x in n.split(".")]
            number = 0
            for address in addresses:
                number *= 2 ** 8
                number += address
            print(number)
        else:
            number = int(n)
            addresses = []
            for _ in range(8):
                addresses.append(number % 2 ** 8)
                number //= 2 ** 8
            print(".".join(str(x) for x in reversed(addresses)))


main()
