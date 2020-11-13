def main():
    while True:
        message = input()
        if message == "END":
            break
        print(message[::-1])


main()
