n, k = (int(x) for x in input().split())
if k > 356 or n <= 2 ** k:
    print("Your wish is granted!")
else:
    print("You will become a flying monkey!")
