from string import ascii_lowercase, ascii_uppercase, digits


special = "+_)(*&^%$#@!./,;{}"
n = int(input())
for _ in range(n):
    input()
    password = input()
    if any(c in ascii_lowercase for c in password) and any(c in ascii_uppercase for c in password) \
        and any(c in digits for c in password) and any(c in special for c in password) and len(password) >= 12:
        print("valid")
    else:
        print("invalid")
