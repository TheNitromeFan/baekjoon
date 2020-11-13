import sys


def main():
    payment = 0
    while True:
        dish = sys.stdin.readline().rstrip()
        if dish == "TOTAL":
            break
        pi, ci = (int(x) for x in sys.stdin.readline().rstrip().split())
        payment += pi * ci
    bill = int(sys.stdin.readline())
    if bill <= payment:
        print("PAY")
    else:
        print("PROTEST")


main()
