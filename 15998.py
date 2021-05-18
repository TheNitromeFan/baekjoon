import sys
import math


def simulate(transactions, m):
    balance = 0
    for a, b in transactions:
        if a > 0:
            balance += a
            if balance != b:
                return False
        elif balance + a >= 0:
            balance += a
            if balance != b:
                return False
        else:
            k = -((a + balance) // m)
            balance += k * m + a
            if balance != b:
                return False
    return True


def main():
    n = int(sys.stdin.readline())
    transactions = []
    for _ in range(n):
        a, b = (int(x) for x in sys.stdin.readline().split())
        transactions.append((a, b))
    balance = 0
    m = 0
    for a, b in transactions:
        if a > 0:
            balance += a
            if balance != b:
                print(-1)
                return
        elif balance + a >= 0:
            balance += a
            if balance != b:
                print(-1)
                return
        else:
            loan = b - a - balance
            m = math.gcd(m, loan)
            balance = b
    if m == 0:
        print(1)
    elif simulate(transactions, m):
        print(m)
    else:
        print(-1)


main()
