from base64 import b16decode

print(b16decode(input().encode('ascii')).decode('ascii'))
