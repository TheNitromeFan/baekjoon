import itertools
import string


def value(s):
    ret = 0
    for c in s:
        x = ord(c)
        ret += x ** 814
        ret %= 20200429
    return ret


def main():
    alphabet = string.ascii_letters + string.digits
    for s in itertools.combinations_with_replacement(alphabet, r=5):
        cand = "".join(s)
        print(cand)
        if value(cand) == 20200402:
            print(cand)
            return


main()
