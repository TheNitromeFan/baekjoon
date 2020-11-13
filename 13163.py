def main():
    n = int(input())
    for _ in range(n):
        syllables = input().split()
        syllables[0] = "god"
        print("".join(syllables))


main()
