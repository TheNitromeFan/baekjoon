import sys


def main():
    n = int(sys.stdin.readline())
    categories = {}
    for _ in range(n):
        entries = sys.stdin.readline().rstrip().split()
        categories[entries[0]] = entries[2:]
    word_counts = {x: 0 for x in categories}
    for line in sys.stdin.readlines():
        for word in line.rstrip().split():
            for category in categories:
                if word in categories[category]:
                    word_counts[category] += 1
    max_count = max(word_counts.values())
    suggest = [x for x in word_counts if word_counts[x] == max_count]
    suggest.sort()
    for suggestion in suggest:
        sys.stdout.write("{}\n".format(suggestion))


main()
