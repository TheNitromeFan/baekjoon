def product(list1):
    ret = 1
    for item in list1:
        ret *= item
    return ret


def number_count(number):
    ret = {}
    p = 2
    while p ** 2 <= number:
        if number % p == 0:
            ret[p] = 0
        while number % p == 0:
            ret[p] += 1
            number //= p
        p += 1
    if number > 1:
        ret[number] = 1
    return ret


def main():
    n = int(input())
    numbers = [int(x) for x in input().split()]
    number_counts = [number_count(number) for number in numbers]
    total_counts = {}
    for nc in number_counts:
        for key, val in nc.items():
            if key in total_counts:
                total_counts[key] += val
            else:
                total_counts[key] = val
    reduced_counts = {key: val // n for key, val in total_counts.items()}
    cnt = 0
    for nc in number_counts:
        for key in reduced_counts:
            if key in nc and nc[key] < reduced_counts[key]:
                cnt += reduced_counts[key] - nc[key]
            elif key not in nc:
                cnt += reduced_counts[key]
    print("{} {}".format(product(key ** val for key, val in reduced_counts.items()), cnt))


main()
