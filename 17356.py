def main():
    a, b = (int(x) for x in input().split())
    print(1 / (1 + 10 ** ((b - a) / 400)))


main()
