def main():
    while True:
        n = int(input())
        if n == -1:
            break
        s = bin(n)[2:]
        s = s[::-1] + "0" * (32 - len(s))
        print(int(s, base=2))


main()
