cnt = 0
while True:
    cnt += 1
    n = int(input())
    if n == 0:
        break
    songs = [input() for _ in range(n)]
    print(cnt)
    print("\n".join(sorted(songs, key=lambda x: x.lower())))
