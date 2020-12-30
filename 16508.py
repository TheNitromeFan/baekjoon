import sys
import itertools
import string


def minimum_cut(word, books, n):
    ret = 10 ** 100
    found = False
    for i in range(n + 1):
        for comb in itertools.combinations(books, i):
            pay, letters = 0, ""
            for price, title in comb:
                pay += price
                letters += title
            if all(letters.count(x) >= word.count(x) for x in string.ascii_uppercase) and ret > pay:
                ret = pay
                found = True
    if not found:
        return -1
    return ret


def main():
    t = sys.stdin.readline().rstrip()
    n = int(sys.stdin.readline())
    books = []
    for _ in range(n):
        price, title = sys.stdin.readline().rstrip().split()
        books.append((int(price), title))
    print(minimum_cut(t, books, n))


main()
