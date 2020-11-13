def is_substring(word, abbreviation):
    ind = 0
    n = len(abbreviation)
    for character in word:
        if abbreviation[ind] == character:
            ind += 1
            if ind == n:
                return True
    return ind == n


def main():
    k = int(input())
    for i in range(k):
        n = int(input())
        print("Data Set {}:".format(i+1))
        words = [input() for _ in range(n)]
        abbreviation = input().lower()
        for word in words:
            if is_substring(word.lower(), abbreviation):
                print(word)



main()
