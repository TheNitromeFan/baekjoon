def main():
    phrase = input().upper()
    kangaroos, kiwis = 0, 0
    for letter in phrase:
        kangaroos += "KANGAROO".count(letter)
        kiwis += "KIWIBIRD".count(letter)
    if kangaroos > kiwis:
        print("Kangaroos")
    elif kangaroos < kiwis:
        print("Kiwis")
    else:
        print("Feud continues")


main()
