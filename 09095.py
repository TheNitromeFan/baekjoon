partitions = {1: 1, 2: 2, 3: 4}


def ways(number):
    if number not in partitions.keys():
        partitions[number] = ways(number-1) + ways(number-2) + ways(number-3)
    return partitions[number]


for i in range(int(input())):
    print(ways(int(input())))
