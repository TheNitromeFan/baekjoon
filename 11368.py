def main():
    while True:
        c, w, l, p = (int(x) for x in input().split())
        if not (c or w or l or p):
            break
        print(c ** (w * l * p))


main()
