import sys


def main():
    cows = ['Bessie', 'Elsie', 'Daisy', 'Gertie', 'Annabelle', 'Maggie', 'Henrietta']
    milk = {cow: 0 for cow in cows}
    m = int(sys.stdin.readline())
    for _ in range(m):
        entries = sys.stdin.readline().split()
        cow, amount = entries[0], int(entries[1])
        milk[cow] += amount
    cows.sort(key=lambda cow: milk[cow])
    lowest = milk[cows[0]]
    i = 0
    while i < 7 and milk[cows[i]] == lowest:
        i += 1
    if i < 7 and (i + 1 == 7 or (i + 1 < 7 and milk[cows[i]] < milk[cows[i + 1]])):
        print(cows[i])
    else:
        print("Tie")


main()
