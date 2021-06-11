import sys


def multiply(m, x, y):
    neg = False
    if x[0] == "-":
        neg = not neg
        x = x[1]
    if y[0] == "-":
        neg = not neg
        y = y[1]
    res = m[(x, y)]
    if neg and res[0] == "-":
        res = res[1]
    elif neg:
        res = "-" + res
    return res


def is_dijkstra(m, string, length, x):
    prod = "1"
    for c in string:
        prod = multiply(m, prod, c)
    if prod == "1":
        return False
    elif prod == "-1" and x % 2 == 0:
        return False
    elif prod != "-1" and x % 4 != 2:
        return False
    left = 0
    prod = "1"
    for _ in range(min(x, 4)):
        for c in string:
            prod = multiply(m, prod, c)
            left += 1
            if prod == "i":
                break
        if prod == "i":
            break
    if prod != "i":
        return False
    right = 0
    prod = "1"
    for _ in range(max(x, 4)):
        for c in string[::-1]:
            prod = multiply(m, c, prod)
            right += 1
            if prod == "k":
                break
        if prod == "k":
            break
    if prod != "k":
        return False
    return left + right < length * x


def main():
    t = int(sys.stdin.readline())
    m = {("1", "1"): "1", ("1", "i"): "i", ("1", "j"): "j", ("1", "k"): "k", ("i", "1"): "i", ("i", "i"): "-1",
         ("i", "j"): "k", ("i", "k"): "-j", ("j", "1"): "j", ("j", "i"): "-k", ("j", "j"): "-1", ("j", "k"): "i",
         ("k", "1"): "k", ("k", "i"): "j", ("k", "j"): "-i", ("k", "k"): "-1"}
    for a0 in range(1, t + 1):
        length, x = (int(z) for z in sys.stdin.readline().split())
        string = sys.stdin.readline().rstrip()
        if is_dijkstra(m, string, length, x):
            print(f"Case #{a0}: YES")
        else:
            print(f"Case #{a0}: NO")


main()
