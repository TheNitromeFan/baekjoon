n = int(input())
for _ in range(n):
    max_decimal = 0
    total = 0
    numbers = []
    while True:
        x = input()
        if x == '0':
            break
        if '.' not in x:
            x = x + '.0'
        decimal = len(x) - 1 - x.find('.')
        if decimal > max_decimal:
            max_decimal = decimal
        numbers.append(x)
    for x in numbers:
        if len(x) - 1 - x.find('.') < max_decimal:
            x = x + '0' * (max_decimal - len(x) + 1 + x.find('.'))
        number = int(x.replace('.', ''))
        total += number
    total = str(total)
    negative = False
    if total[0] == '-':
        negative = True
        total = total[1:]
    if len(total) < max_decimal + 1:
        total = '0' * (max_decimal + 1 - len(total)) + total
    total = total[:-max_decimal] + '.' + total[-max_decimal:]
    total = total.strip('0')
    if total.find('.') == 0:
        total = '0' + total
    if total.find('.') == len(total)-1:
        total = total[:-1]
    if negative:
        total = '-' + total
    print(total)
