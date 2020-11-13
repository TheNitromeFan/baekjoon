def main():
    while True:
        line = input()
        if line == "-1":
            break
        numbers = {int(x) for x in line.split()} - {0}
        print(sum(1 for x in numbers if 2 * x in numbers))


main()
