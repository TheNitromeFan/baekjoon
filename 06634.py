import sys


def main():
    display = ["+---+|   ||   |+   +|   ||   |+---+", "    +    |    |    +    |    |    +",
               "+---+    |    |+---+|    |    +---+", "+---+    |    |+---+    |    |+---+",
               "+   +|   ||   |+---+    |    |    +", "+---+|    |    +---+    |    |+---+",
               "+---+|    |    +---+|   ||   |+---+", "+---+    |    |    +    |    |    +",
               "+---+|   ||   |+---+|   ||   |+---+", "+---+|   ||   |+---+    |    |+---+"]
    while True:
        time = sys.stdin.readline().rstrip()
        if time == "end":
            print("end")
            break
        for i in range(0, 5 * 7, 5):
            symbols = []
            for digit in time:
                if digit == ":":
                    if i == 5 * 2 or i == 5 * 4:
                        symbols.append("o")
                    else:
                        symbols.append(" ")
                else:
                    symbols.append(display[int(digit)][i:i + 5])
            print("  ".join(symbols))
        print()
        print()


main()
