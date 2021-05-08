import sys
import string


def is_valid_key(old_section, key, new_section):
    for i in range(len(old_section)):
        if (old_section[i] + key[i % len(key)]) % 26 != new_section[i]:
            return False
    return True


def has_valid_key(old_section, new_section):
    for length in range(1, len(old_section) // 2 + 1):
        key = [(new_section[i] - old_section[i]) % 26 for i in range(length)]
        if is_valid_key(old_section, key, new_section):
            return key
    return []


def subtract(encrypted, key):
    ret = encrypted[::]
    for i in range(len(ret)):
        ret[i] = (ret[i] - key[i % len(key)]) % 26
    return ret


def main():
    encrypted = [string.ascii_lowercase.index(c) for c in sys.stdin.readline().rstrip()]
    section = [string.ascii_lowercase.index(c) for c in sys.stdin.readline().rstrip()]
    for pos in range(1, len(encrypted) - len(section) + 1):
        key = has_valid_key(section, encrypted[pos:pos + len(section)])
        if key:
            for _ in range(pos % len(key)):
                key.insert(0, key.pop())
            decrypted = subtract(encrypted, key)
            print("".join(string.ascii_lowercase[x] for x in decrypted))


main()
