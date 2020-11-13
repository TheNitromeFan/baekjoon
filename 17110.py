def main():
    n = int(input())
    countries = [input() for _ in range(n)]
    price = 0
    for ind, country in enumerate(countries):
        if country in ["ethiopia", "kenya", "tanzania"]:
            price += 50
        elif country == "namibia":
            if "south-africa" in countries[:ind]:
                price += 40
            else:
                price += 140
        elif country == "zambia":
            price += 50
            if ind > 0 and countries[ind - 1] == "zimbabwe":
                price -= 30
        elif country == "zimbabwe":
            price += 30
            if ind > 0 and countries[ind - 1] == "zambia":
                price -= 30
    if n == 8 and (countries[0] != "kenya" or countries[1] != "tanzania"):
        print(-1)
    else:
        print(price)


main()
