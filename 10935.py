from base64 import b64encode

print(b64encode(input().encode('ascii')).decode('ascii'))
