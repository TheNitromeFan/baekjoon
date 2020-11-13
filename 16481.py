def main():
    ra, rb, rc = (int(x) for x in input().split())
    print((ra * rb * rc) / (ra * rb + rb * rc + rc * ra))


main()
