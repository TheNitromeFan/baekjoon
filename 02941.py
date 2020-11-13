croatian = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]


def letters(string):
    for alphabet in croatian:
        string = string.replace(alphabet, "*")
    return len(string)


print(letters(input()))
