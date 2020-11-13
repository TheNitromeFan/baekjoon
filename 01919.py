from string import ascii_lowercase


def main():
    string1, string2 = input(), input()
    count1 = {x: string1.count(x) for x in ascii_lowercase}
    count2 = {x: string2.count(x) for x in ascii_lowercase}
    count_diff = {x: abs(count1[x] - count2[x]) for x in ascii_lowercase}
    print(sum(count_diff.values()))


main()
