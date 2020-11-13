from base64 import b32encode

print(b32encode(input().encode('ascii')).decode('ascii'))
