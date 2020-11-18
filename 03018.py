import sys


def main():
    n = int(sys.stdin.readline())
    e = int(sys.stdin.readline())
    songs = {x: set() for x in range(1, n + 1)}
    for i in range(e):
        people = [int(x) for x in sys.stdin.readline().split()][1:]
        if 1 in people:
            for person in people:
                songs[person].add(i)
        else:
            total_songs = set()
            for person in people:
                total_songs |= songs[person]
            for person in people:
                songs[person] = total_songs.copy()
        # print(songs)
    for person in range(1, n + 1):
        if len(songs[person]) == len(songs[1]):
            print(person)


main()
