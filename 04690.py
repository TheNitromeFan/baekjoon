def main():
    for a in range(1, 101):
        for b in range(2, 70):
            for c in range(b, 80):
                for d in range(c, 100):
                    if a**3 == b**3 + c**3 + d**3:
                        print("Cube = {}, Triple = ({},{},{})".format(a, b, c, d))


main()
