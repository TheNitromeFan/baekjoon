def compare_letters(s):
    letters = {'A': '000000', 'B': '001111', 'C': '010011', 'D': '011100',
               'E': '100110', 'F': '101001', 'G': '110101', 'H': '111010'}
    diffs = []
    for k, v in letters.items():
        diff_cnt = sum(1 for i in range(6) if s[i] != v[i])
        diffs.append((diff_cnt, k))
    diffs.sort()
    if diffs[0][0] == diffs[1][0]:
        return False
    return diffs[0][1]


def main():
    n = int(input())
    s = input()
    letters = ""
    for i in range(n):
        letter = compare_letters(s[6 * i:6 * i + 6])
        if letter:
            letters += letter
        else:
            print(i + 1)
            return
    print(letters)


main()
