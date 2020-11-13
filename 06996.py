def main():
    n = int(input())
    for _ in range(n):
        a, b = input().split()
        if sorted(a) == sorted(b):
            print("{} & {} are anagrams.".format(a, b))
        else:
            print("{} & {} are NOT anagrams.".format(a, b))


main()
