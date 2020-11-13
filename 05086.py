def relation(first, second):
    if second % first == 0:
        return "factor"
    elif first % second == 0:
        return "multiple"
    return "neither"


while True:
    a, b = (int(x) for x in input().split())
    if a == 0 and b == 0:
        break
    print(relation(a, b))
