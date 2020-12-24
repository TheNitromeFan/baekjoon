def valid_quote(quote):
    if quote.count("<<") != quote.count(">>"):
        return "Keine Loesung"
    stack = []
    ret = ""
    for i in range(0, len(quote), 2):
        if stack and quote[i] != quote[stack[0]]:
            ret += "]"
            stack.pop()
        else:
            ret += "["
            stack.append(i)
    if stack:
        return "Keine Loesung"
    else:
        return ret


def main():
    quote = input()
    print(valid_quote(quote))


main()
