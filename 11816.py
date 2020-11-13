def main():
    x = input()
    if x[:2] == "0x":
        ans = int(x, base=16)
    elif x[0] == "0":
        ans = int(x, base=8)
    else:
        ans = x
    print(ans)


main()
