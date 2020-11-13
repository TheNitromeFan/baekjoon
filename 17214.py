polynomial = input().split('x')
if len(polynomial) == 2:
    a = int(polynomial[0])
    if a == 2:
        print('xx', end='')
    elif a == -2:
        print('-xx', end='')
    else:
        print('{}xx'.format(a // 2), end='')
    if polynomial[1]:
        b = int(polynomial[1])
        if b == 1:
            print('+x', end='')
        elif b == -1:
            print('-x', end='')
        elif b < 0:
            print('{}x'.format(b), end='')
        elif b > 0:
            print('+{}x'.format(b), end='')
    print('+W')
else:
    b = int(polynomial[0])
    if b == 1:
        print('x+', end='')
    elif b == -1:
        print('-x+', end='')
    elif b:
        print('{}x+'.format(b), end='')
    print('W')
