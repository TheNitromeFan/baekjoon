polynomial = input().split('x')
if len(polynomial) == 2:
    if not polynomial[0]:
        a = 1
    elif polynomial[0] == "-":
        a = -1
    else:
        a = int(polynomial[0])
    print(a)
else:
    print(0)
