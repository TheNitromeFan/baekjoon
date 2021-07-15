import sys


def count_albums_and_pics(adj, cur):
    albums, pics = 1, 0
    for name, is_album in adj[cur]:
        if is_album:
            x, y = count_albums_and_pics(adj, name)
            albums += x
            pics += y
        else:
            pics += 1
    adj.pop(cur)
    return albums, pics


def main():
    path = ["album"]
    cur = "album"
    n = int(sys.stdin.readline())
    adj = {"album": []}
    cnt = {"album": [1, 0]}
    for _ in range(n):
        cmd, arg = sys.stdin.readline().rstrip().split()
        if cmd == "mkalb":
            arg1 = cur + "/" + arg
            if (arg1, True) in adj[cur]:
                sys.stdout.write("duplicated album name\n")
            else:
                adj[arg1] = []
                cnt[arg1] = [1, 0]
                adj[cur].append((arg1, True))
        elif cmd == "rmalb":
            arg1 = cur + "/" + arg
            if arg == "-1":
                album_names = [x for x, y in adj[cur] if y]
                if album_names:
                    name = min(album_names)
                    album_count, pic_count = count_albums_and_pics(adj, name)
                    adj[cur].remove((name, True))
                    sys.stdout.write(f"{album_count} {pic_count}\n")
                else:
                    sys.stdout.write("0 0\n")
            elif arg == "0":
                total_album_count, total_pic_count = 0, 0
                album_names = [x for x, y in adj[cur] if y]
                for name in album_names:
                    album_count, pic_count = count_albums_and_pics(adj, name)
                    total_album_count += album_count
                    total_pic_count += pic_count
                    adj[cur].remove((name, True))
                sys.stdout.write(f"{total_album_count} {total_pic_count}\n")
            elif arg == "1":
                album_names = [x for x, y in adj[cur] if y]
                if album_names:
                    name = max(album_names)
                    album_count, pic_count = count_albums_and_pics(adj, name)
                    adj[cur].remove((name, True))
                    sys.stdout.write(f"{album_count} {pic_count}\n")
                else:
                    sys.stdout.write("0 0\n")
            else:
                if (arg1, True) in adj[cur]:
                    album_count, pic_count = count_albums_and_pics(adj, arg1)
                    adj[cur].remove((arg1, True))
                    sys.stdout.write(f"{album_count} {pic_count}\n")
                else:
                    sys.stdout.write("0 0\n")
        elif cmd == "insert":
            if (arg, False) in adj[cur]:
                sys.stdout.write("duplicated photo name\n")
            else:
                adj[cur].append((arg, False))
        elif cmd == "delete":
            if arg == "-1":
                pic_names = [x for x, y in adj[cur] if not y]
                if pic_names:
                    name = min(pic_names)
                    adj[cur].remove((name, False))
                    sys.stdout.write("1\n")
                else:
                    sys.stdout.write("0\n")
            elif arg == "0":
                pic_names = [x for x, y in adj[cur] if not y]
                pic_count = len(pic_names)
                for name in pic_names:
                    adj[cur].remove((name, False))
                sys.stdout.write(f"{pic_count}\n")
            elif arg == "1":
                pic_names = [x for x, y in adj[cur] if not y]
                if pic_names:
                    name = max(pic_names)
                    adj[cur].remove((name, False))
                    sys.stdout.write("1\n")
                else:
                    sys.stdout.write("0\n")
            else:
                if (arg, False) in adj[cur]:
                    adj[cur].remove((arg, False))
                    sys.stdout.write("1\n")
                else:
                    sys.stdout.write("0\n")
        else:
            if arg == "..":
                if cur != "album":
                    path.pop()
                    cur = "/".join(path)

            elif arg == "/":
                path = ["album"]
                cur = "album"
            else:
                arg1 = cur + "/" + arg
                if (arg1, True) in adj[cur]:
                    path.append(arg)
                    cur = arg1
            sys.stdout.write(f"{path[-1]}\n")
        print(adj, cur)


main()
