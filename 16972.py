x, y = 0, 0
for i in range(1, 815):
    print("{} {}".format(x, y))
    if i % 4 == 0:
        x += i
    elif i % 4 == 1:
        y += i
    elif i % 4 == 2:
        x -= i
    else:
        y -= i
