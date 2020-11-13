def is_vpn(parentheses):
    left = 0
    right = 0
    for parenthesis in parentheses:
        if parenthesis is "(":
            left += 1
        else:
            right += 1
        if left < right:
            return False
    return left == right


def vpn(parentheses):
    if is_vpn(parentheses):
        return "YES"
    else:
        return "NO"


for i in range(int(input())):
    print(vpn(input()))
