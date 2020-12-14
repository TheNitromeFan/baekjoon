import sys


def main():
    n = int(sys.stdin.readline())
    emails = set()
    for _ in range(n):
        address = sys.stdin.readline().rstrip()
        username, provider = address.split("@")
        username = username.split("+")[0].replace(".", "")
        emails.add((username, provider))
    sys.stdout.write("{}".format(len(emails)))


main()
