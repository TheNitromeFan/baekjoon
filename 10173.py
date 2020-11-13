def main():
    while True:
        line = input()
        if line == "EOI":
            break
        if "nemo" in line.lower():
            print("Found")
        else:
            print("Missing")


main()
