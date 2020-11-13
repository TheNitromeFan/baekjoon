import hashlib


def main():
    s = input()
    h = hashlib.new("ripemd160")
    h.update(s.encode("UTF-8"))
    print(h.hexdigest())


main()
