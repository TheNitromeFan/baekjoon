'''
cnt = {x: 0 for x in range(1, 46)}
with open("15637.txt", "r") as f:
    for line in f:
        numbers = line.rstrip().split()
        for number in numbers:
            cnt[int(number)] += 1
for i, v in cnt.items():
    print("{}: {}, ".format(i, v), end="")
'''

cnt = {1: 103, 2: 88, 3: 91, 4: 99, 5: 101, 6: 86, 7: 96, 8: 100, 9: 71, 10: 91, 11: 96, 12: 91, 13: 98, 14: 102,
       15: 96, 16: 85, 17: 102, 18: 97, 19: 91, 20: 112, 21: 85, 22: 79, 23: 86, 24: 91, 25: 97, 26: 98, 27: 110,
       28: 80, 29: 88, 30: 80, 31: 95, 32: 83, 33: 93, 34: 109, 35: 88, 36: 91, 37: 103, 38: 90, 39: 95, 40: 113,
       41: 81, 42: 86, 43: 97, 44: 93, 45: 93}
print(cnt[int(input())])
