from base64 import b64decode

print(b64decode(input().encode('ascii')).decode('ascii'))
