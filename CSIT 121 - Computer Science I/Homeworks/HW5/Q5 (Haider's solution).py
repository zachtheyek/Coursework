bits = input("Enter a bit string: ")

if len(bits) > 1:
 bits = bits[1:] + bits[0] # bits = "10011" + "1"

print(bits)