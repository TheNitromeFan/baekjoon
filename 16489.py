from decimal import Decimal, getcontext


def main():
    getcontext().prec = 100
    a, b, c = (Decimal(x) for x in input().split())
    s = (a + b + c) / 2
    area = (s * (s - a) * (s - b) * (s - c)).sqrt()
    circumradius = a * b * c / 4 / area
    inradius = area / s
    d = (circumradius * (circumradius - 2 * inradius)).sqrt()
    k = circumradius + inradius
    for val in [area, circumradius, inradius, d, k]:
        if 'E' in str(val):
            print(0)
        else:
            print(val)
    '''
    fifteen_places = Decimal(10) ** -20
    print(area.quantize(fifteen_places))
    print(circumradius.quantize(fifteen_places))
    print(inradius.quantize(fifteen_places))
    if d < fifteen_places:
        d = 0
    else:
        d = d.quantize(fifteen_places)
    print(d)
    print((circumradius + inradius).quantize(fifteen_places))
    '''



main()
