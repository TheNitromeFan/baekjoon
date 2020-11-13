def main():
    n = int(input())
    b = [int(x) for x in input().split()]
    bacteria = 1
    for bi in b:
        bacteria = bacteria * 2 - bi
        if bacteria < 0:
            print("error")
            return
    print(bacteria % (10 ** 9 + 7))


main()
