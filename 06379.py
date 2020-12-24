import sys
import string


def scramble_sorted(items):
    numbers, words = [], []
    is_digit = [False] * len(items)
    for idx, item in enumerate(items):
        if item[-1] in string.digits:
            numbers.append(int(item))
            is_digit[idx] = True
        else:
            words.append(item)
    numbers.sort()
    words.sort(key=lambda x: x.lower())
    sorted_items = []
    i, j = 0, 0
    for idx in range(len(items)):
        if is_digit[idx]:
            sorted_items.append(str(numbers[i]))
            i += 1
        else:
            sorted_items.append(words[j])
            j += 1
    return sorted_items


def main():
    for line in sys.stdin.readlines():
        line = line.rstrip()
        if not line or line == ".":
            break
        items = line[:-1].split(", ")
        sys.stdout.write("{}.\n".format(", ".join(scramble_sorted(items))))


main()
