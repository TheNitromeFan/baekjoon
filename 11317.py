def main():
    n = int(input())
    for _ in range(n):
        a, b, c, s, t = (int(x) for x in input().split())
        discriminant = b ** 2 - 4 * a * c
        if discriminant > 0:
            x1, x2 = (-b - discriminant ** 0.5) / (2 * a), (-b + discriminant ** 0.5) / (2 * a)
            if s <= x1 <= t or s <= x2 <= t:
                print("Yes")
            else:
                print("No")
        elif discriminant == 0:
            x = -b / (2 * a)
            if s <= x <= t:
                print("Yes")
            else:
                print("No")
        else:
            print("No")


main()
