from base64 import b32decode

print(b32decode(input().encode('ascii')).decode('ascii'))
