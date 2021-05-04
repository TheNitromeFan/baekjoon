import sys


def main():
    n, s = (int(x) for x in sys.stdin.readline().split())
    birds = sys.stdin.readline().rstrip().split()
    for _ in range(s):
        entries = sys.stdin.readline().rstrip().split()
        if entries[0] == "insert":
            bird_name, position = entries[1], int(entries[2])
            birds.insert(position, bird_name)
        elif entries[0] == "depart":
            bird_name = entries[1]
            birds.remove(bird_name)
        else:
            bird_name, displacement = entries[1], int(entries[2])
            i = birds.index(bird_name)
            birds.insert(i + displacement, birds.pop(i))
    print(" ".join(birds))


main()
