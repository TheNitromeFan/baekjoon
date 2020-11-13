def main():
    t = int(input())
    for _ in range(t):
        input()
        key1 = input().split()
        key2 = input().split()
        code_words = input().split()
        translation = {key: code for key, code in zip(key2, code_words)}
        print(" ".join(translation[key] for key in key1))


main()
