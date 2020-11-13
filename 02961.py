def main():
    n = int(input())
    ingredients = []
    for _ in range(n):
        s, b = input().split()
        ingredients.append((int(s), int(b)))
    ans = 10 ** 90
    for recipe in range(1, 2 ** n):
        k = recipe
        sour, bitter = 1, 0
        for i in range(n):
            if k % 2:
                sour *= ingredients[i][0]
                bitter += ingredients[i][1]
            k //= 2
        if abs(sour - bitter) < ans:
            ans = abs(sour - bitter)
    print(ans)


main()
