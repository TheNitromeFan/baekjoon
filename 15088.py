import sys


def main():
    n, _ = (int(x) for x in sys.stdin.readline().split())
    commands = sys.stdin.readline().split()
    throws = []
    i = 0
    while i < len(commands):
        if commands[i] == "undo":
            i += 1
            erase = int(commands[i])
            for _ in range(erase):
                throws.pop()
            i += 1
        else:
            throws.append(int(commands[i]))
            i += 1
    print(sum(throws) % n)


main()
