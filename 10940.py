from base64 import b16encode

print(b16encode(input().encode('ascii')).decode('ascii'))
