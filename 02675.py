def repeat(number, string):
    return "".join(letter * number for letter in string)


def main(line):
    r, s = line.split()
    print(repeat(int(r), s))


for i in range(int(input())):
    main(input())
