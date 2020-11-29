import sys


def shortest_identifying_string(songs, song):
    for length in range(len(song) + 1):
        ret = []
        for i in range(len(song) - length + 1):
            if len([s for s in songs if song[i: i + length] in s]) == 1:
                ret.append(song[i: i + length])
        if ret:
            return '"' + sorted(ret)[0] + '"'
    return ":("


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        n = int(sys.stdin.readline())
        songs = []
        for _ in range(n):
            songs.append(sys.stdin.readline().rstrip().upper())
        sys.stdout.write("Case #{}:\n".format(a0))
        for song in songs:
            sys.stdout.write('{}\n'.format(shortest_identifying_string(songs, song)))


main()
