import sys


def game():
    lower_bound, higher_bound = 0, 11
    while True:
        n = int(sys.stdin.readline())
        if n == 0:
            return False
        answer = sys.stdin.readline().rstrip()
        if answer == "too high" and higher_bound > n:
            higher_bound = n
        elif answer == "too low" and lower_bound < n:
            lower_bound = n
        elif answer == "right on":
            if lower_bound < n < higher_bound:
                print("Stan may be honest")
            else:
                print("Stan is dishonest")
            return True


def main():
    while True:
        if not game():
            break


main()
