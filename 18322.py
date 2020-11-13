def main():
    n, k = (int(x) for x in input().split())
    words = input().split()
    line = []
    char_count = 0
    for word in words:
        if char_count + len(word) <= k:
            line.append(word)
            char_count += len(word)
        else:
            print(" ".join(line))
            line = [word]
            char_count = len(word)
    print(" ".join(line))


main()
