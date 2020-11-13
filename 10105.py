import sys


def main():
    sys.stdin.readline()
    names1 = sys.stdin.readline().rstrip().split()
    names2 = sys.stdin.readline().rstrip().split()
    pairs = {}
    for name1, name2 in zip(names1, names2):
        pairs[name1] = name2
    if all(pairs[pairs[name]] == name for name in pairs) and not any(pairs[name] == name for name in pairs):
        print("good")
    else:
        print("bad")


main()
