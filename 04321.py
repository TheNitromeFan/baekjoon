import sys


while True:
    line = sys.stdin.readline().rstrip()
    if line == "-":
        break
    total_calories = 0
    fat_calories = 0
    while line != "-":
        entries = line.split()
        calories = [0, 0, 0, 0, 0]
        percent = 100
        for i, entry in enumerate(entries):
            if entry[-1] == "%":
                percent -= int(entry[:-1])
            elif entry[-1] == "g":
                if i == 0:
                    calories[i] = 9 * int(entry[:-1])
                elif i == 4:
                    calories[i] = 7 * int(entry[:-1])
                else:
                    calories[i] = 4 * int(entry[:-1])
            else:
                calories[i] = int(entry[:-1])
        ingredient_calories = sum(calories) / percent * 100
        for i, entry in enumerate(entries):
            if entry[-1] == "%":
                calories[i] = ingredient_calories / 100 * int(entry[:-1])
        fat_calories += calories[0]
        total_calories += sum(calories)
        line = sys.stdin.readline().rstrip()
    print(f"{round(fat_calories * 100 / total_calories)}%")
