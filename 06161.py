import sys


def main():
    n, t = (int(x) for x in sys.stdin.readline().split())
    songs = []
    for i in range(n):
        rating = int(sys.stdin.readline())
        songs.append(rating)
    for _ in range(t):
        points = max(songs)
        song = songs.index(points)
        print(song + 1)
        songs[song] = 0
        d, m = divmod(points, n - 1)
        for i in range(n):
            if i != song:
                songs[i] += d
        i = 0
        while m:
            if i != song:
                songs[i] += 1
                m -= 1
            i += 1


main()
