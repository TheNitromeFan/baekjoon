def main():
    n = int(input())
    low, high = 1, 10 ** 400
    while True:
        mid = (low + high) // 2
        if mid * mid == n:
            print(mid)
            break
        elif mid * mid < n:
            low = mid + 1
        else:
            high = mid


main()
