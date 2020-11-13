import hashlib


def main():
    s = input()
    h = hashlib.new("sha")
    h.update(s.encode("ascii"))
    print(h.hexdigest())


main()
