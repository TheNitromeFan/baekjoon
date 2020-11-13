def is_digit(word):
    try:
        int(word)
        return True
    except ValueError:
        return False


def main():
    while True:
        line = input().lower()
        if line == '#':
            break
        line_stripped = line
        for c in line:
            if c != ' ' and not 'a' <= c <= 'z' and not '0' <= c <= '9':
                line_stripped = line_stripped.replace(c, '')
        words = set()
        for word in line_stripped.split():
            if not is_digit(word):
                words.add(word)
        for word in sorted(words):
            print(word)
        print()


main()
