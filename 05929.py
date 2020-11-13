def convert_base(num, base1, base2):
    n = 0
    for x in num:
        n *= base1
        n += int(x)
    if n == 0:
        return "0"
    ret = ""
    while n > 0:
        ret = str(n % base2) + ret
        n //= base2
    return ret


def compare_differences(str1, str2):
    if len(str1) != len(str2):
        return None
    ret = 0
    for i in range(len(str1)):
        if str1[i] != str2[i]:
            ret += 1
    return ret


def main():
    binary = input()
    ternary = input()
    for i, v in enumerate(binary):
        if v == "0":
            new_binary = binary[:i] + "1" + binary[i+1:]
        else:
            new_binary = binary[:i] + "0" + binary[i+1:]
        new_ternary = convert_base(new_binary, 2, 3)
        if compare_differences(ternary, new_ternary) == 1:
            print(convert_base(new_binary, 2, 10))


main()
