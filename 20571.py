import sys


floors = {("residential", 1): 0, ("commercial", 1): 0, ("industrial", 1): 0}
for floor in range(2, 6):
    floors[("residential", floor)] = 1
for floor in range(6, 11):
    floors[("residential", floor)] = 2
for floor in range(11, 16):
    floors[("residential", floor)] = 3
for floor in range(16, 21):
    floors[("residential", floor)] = 4
for floor in range(2, 8):
    floors[("commercial", floor)] = 1
for floor in range(8, 15):
    floors[("commercial", floor)] = 2
for floor in range(15, 21):
    floors[("commercial", floor)] = 3
for floor in range(2, 5):
    floors[("industrial", floor)] = 1
for floor in range(5, 9):
    floors[("industrial", floor)] = 2
for floor in range(9, 13):
    floors[("industrial", floor)] = 3
for floor in range(13, 17):
    floors[("industrial", floor)] = 4
for floor in range(17, 21):
    floors[("industrial", floor)] = 5
entries = input().split()
zoning, n = entries[0], int(entries[1])
print(floors[(zoning, n)])
