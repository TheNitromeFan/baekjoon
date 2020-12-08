import sys


def main():
    n, m = (int(x) for x in sys.stdin.readline().split())
    words = []
    for _ in range(n):
        words.append(sys.stdin.readline().rstrip())
    count = 0
    for _ in range(m):
        word = sys.stdin.readline().rstrip()
        if any(word1[:len(word)] == word for word1 in words):
            count += 1
    sys.stdout.write("{}".format(count))


main()
