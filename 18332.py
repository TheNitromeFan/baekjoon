import sys


def main():
    n = int(sys.stdin.readline())
    emails = set()
    for _ in range(n):
        address = sys.stdin.readline().rstrip()
        if address.count("@") != 1:
            continue
        username, domain = address.split("@")
        if not username or "-" in username or ".." in username or username[0] == "." or username[-1] == ".":
            continue
        username = username.replace(".", "").lower()
        if not 6 <= len(username) <= 30:
            continue
        if not 3 <= len(domain) <= 30 or "_" in domain or domain[0] == "." or domain[-1] == ".":
            continue
        parts = tuple(part.lower() for part in domain.split("."))
        if "" in parts:
            continue
        emails.add((username, parts))
    print(len(emails))


main()
