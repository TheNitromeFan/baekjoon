import sys
import decimal


decimal.getcontext().prec = 100
tau = decimal.Decimal("6.28318530717958647692528676655900576839433879875021164194988918461563281257241799725606965068423413596429617302656461329418768921910116446345071881625696223490056820540387704221111928924589790986076392885762195133186689225695129646757356633054240381829129713384692069722090865329642678721452049828254744917401321263117634976304184192565850818343072873578518072002266106109764093304276829390388302321886611454073151918390618437223476386522358621023709614892475992549913470377150544978245587636602389825")


def sin(x):
    x %= tau
    decimal.getcontext().prec += 2
    i, lasts, s, fact, num, sign = 1, 0, x, 1, x, 1
    while s != lasts:
        lasts = s
        i += 2
        fact *= i * (i - 1)
        num *= x * x
        sign *= -1
        s += num / fact * sign
    decimal.getcontext().prec -= 2
    return +s


def cos(x):
    return sin(x + tau / 4)


def f(a, b, c, x):
    return a * x + b * sin(x) - c


def df(a, b, x):
    return a + b * cos(x)


a, b, c = (decimal.Decimal(x) for x in sys.stdin.readline().split())
x = (c - b) / a
for _ in range(500):
    x -= f(a, b, c, x) / df(a, b, x)
print(f"{x:.25f}")
