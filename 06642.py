import sys


def main():
    while True:
        n = int(sys.stdin.readline())
        if n == 0:
            print("goodbye")
            break
        accounts = {}
        for _ in range(n):
            entries = sys.stdin.readline().rstrip().split()
            number, amount = entries[0], float(entries[1])
            accounts[number] = amount
        while True:
            command = sys.stdin.readline().rstrip().split()
            if command[0] == "end":
                print("end")
                break
            elif command[0] == "create":
                number = command[1]
                if number in accounts:
                    print("create: already exists")
                else:
                    accounts[number] = 0
                    print("create: ok")
            elif command[0] == "deposit":
                number, amount = command[1], float(command[2])
                if number in accounts:
                    accounts[number] += amount
                    print("deposit {0:.2f}: ok".format(amount))
                else:
                    print("deposit {0:.2f}: no such account".format(amount))
            elif command[0] == "withdraw":
                number, amount = command[1], float(command[2])
                if number in accounts and accounts[number] < amount:
                    print("withdraw {0:.2f}: insufficient funds".format(amount))
                elif number in accounts:
                    accounts[number] -= amount
                    print("withdraw {0:.2f}: ok".format(amount))
                else:
                    print("withdraw {0:.2f}: no such account".format(amount))
            else:
                number1, number2, amount = command[1], command[2], float(command[3])
                if number1 in accounts and number1 == number2:
                    print("transfer {0:.2f}: same account".format(amount))
                elif number1 in accounts and number2 in accounts and accounts[number1] < amount:
                    print("transfer {0:.2f}: insufficient funds".format(amount))
                elif number1 in accounts and number2 in accounts:
                    accounts[number1] -= amount
                    accounts[number2] += amount
                    if number1[-1] == number2[-1]:
                        print("transfer {0:.2f}: ok".format(amount))
                    else:
                        print("transfer {0:.2f}: interbank".format(amount))
                else:
                    print("transfer {0:.2f}: no such account".format(amount))
        print()
        sys.stdin.readline()


main()
