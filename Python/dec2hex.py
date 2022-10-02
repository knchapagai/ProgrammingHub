print("Enter the Decimal Number: ")
decnum = int(input())

i = 0
hexdecnum = []
while decnum!=0:
    rem = decnum % 16
    if rem<10:
        rem = rem+48
    else:
        rem = rem+55
    rem = chr(rem)
    hexdecnum.insert(i, rem)
    i = i+1
    decnum = int(decnum / 16)

print("\nEquivalent Hexadecimal Value is: ")
i = i-1
while i>=0:
    print(end=hexdecnum[i])
    i = i-1
print()
