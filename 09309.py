from string import ascii_uppercase, ascii_lowercase, digits


banned = ["password", "virginia", "cavalier", "code"]


def check_subsequence(word, subsequence):
    i = 0
    for character in word:
        if i == len(subsequence):
            return True
        if character == subsequence[i]:
            i += 1
    return i == len(subsequence)


def check_validity(password):
    if not 9 <= len(password) <= 20:
        return False
    upper_count, lower_count, number_count, non_alnum_count = 0, 0, 0, 0
    for character in password:
        if character in ascii_lowercase:
            lower_count += 1
        elif character in ascii_uppercase:
            upper_count += 1
        elif character in digits:
            number_count += 1
        elif character in "!@#$%^&*.,;/?":
            non_alnum_count += 1
    if upper_count < 2 or lower_count < 2 or number_count < 1 or non_alnum_count < 2:
        return False
    for i in range(len(password) - 2):
        if len(set(password[i: i + 3])) == 1:
            return False
    password = "".join(character for character in password if character in ascii_uppercase + ascii_lowercase + digits)
    password = password.lower()
    if password == password[::-1]:
        return False
    for word in banned:
        if check_subsequence(password, word) or check_subsequence(password[::-1], word):
            return False
    return True


def main():
    n = int(input())
    for _ in range(n):
        password = input()
        if check_validity(password):
            print("Valid Password")
        else:
            print("Invalid Password")


main()
