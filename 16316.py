def is_int(word):
    try:
        int(word)
        return True
    except ValueError:
        return False


def main():
    n = input()
    words = input().split()
    for i, word in enumerate(words, start=1):
        if not ((is_int(word) and int(word) == i) or word == "mumble"):
            print("something is fishy")
            return
    print("makes sense")


main()
