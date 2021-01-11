import sys
import decimal


balance = decimal.Decimal(0)
for _ in range(12):
    balance += decimal.Decimal(sys.stdin.readline())
print(f"${(balance / decimal.Decimal(12)).quantize(decimal.Decimal('0.01'), rounding=decimal.ROUND_HALF_UP)}")
