def resize(line):
    return ''.join(x * 2 for x in line)


def main():
    n, m = (int(x) for x in input().split())
    original = [input() for _ in range(n)]
    resized = [input() for _ in range(n)]
    if all(resize(original[i]) == resized[i] for i in range(n)):
        print("Eyfa")
    else:
        print("Not Eyfa")


main()
