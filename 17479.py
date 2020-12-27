import sys


def main():
    a, b, c = (int(x) for x in sys.stdin.readline().split())
    regular, special, service = {}, {}, set()
    for _ in range(a):
        food, price = sys.stdin.readline().split()
        regular[food] = int(price)
    for _ in range(b):
        food, price = sys.stdin.readline().split()
        special[food] = int(price)
    for _ in range(c):
        food = sys.stdin.readline().rstrip()
        service.add(food)
    n = int(sys.stdin.readline())
    order_regular, order_special, order_service = [], [], []
    for _ in range(n):
        food = sys.stdin.readline().rstrip()
        if food in regular:
            order_regular.append(food)
        elif food in special:
            order_special.append(food)
        elif food in service:
            order_service.append(food)
    money = sum(regular[food] for food in order_regular)
    if order_special and money < 20000:
        sys.stdout.write("No")
        return
    money += sum(special[food] for food in order_special)
    if order_service and money < 50000:
        sys.stdout.write("No")
        return
    if len(order_service) > 1:
        sys.stdout.write("No")
    else:
        sys.stdout.write("Okay")


main()
