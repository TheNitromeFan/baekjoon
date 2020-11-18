import sys


def can_make_sign(word, sign):
    m, n = len(word), len(sign)
    for i in range(n):
        for j in range(1, n):
            if i + (m - 1) * j >= n:
                break
            if "".join(sign[x] for x in range(i, i + m * j, j)) == word:
                return True
    return False


def main():
    n = int(sys.stdin.readline())
    word = sys.stdin.readline().rstrip()
    count = 0
    for _ in range(n):
        sign = sys.stdin.readline().rstrip()
        if can_make_sign(word, sign):
            count += 1
    print(count)


main()
