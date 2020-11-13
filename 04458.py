def main():
    n = int(input())
    for _ in range(n):
        sentence = input()
        print(sentence[0].upper() + sentence[1:])


main()
