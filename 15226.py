def main():
    n = int(input())
    while n % 8 not in [0, 5]:
        n += 1
    print(n)


main()
